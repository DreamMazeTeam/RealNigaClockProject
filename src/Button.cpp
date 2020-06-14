#include "Button.h"
#include <Arduino.h>

// ==================== CONSTRUCTOR ====================
CButton::CButton(int8_t pin, bool type, bool dir) {
	if (CButton::first == nullptr)
		CButton::first = this;
	else
		CButton::last->next = this;
	CButton::last = this;

	if (pin != BTN_NO_PIN) {
		_PIN = (uint8_t)pin;
		flags.noPin = false;
	} else {
		flags.noPin = true;
	}
	setType(type);
	flags.mode = false;
	flags.tickMode = false;
	flags.inv_state = dir;
}

CButton* CButton::button = nullptr;
CButton* CButton::first = nullptr;
CButton* CButton::last = nullptr;

// ==================== SET ====================
void CButton::setDebounce(uint16_t debounce) {
	_debounce = debounce;
}
void CButton::setTimeout(uint16_t new_timeout) {
	_timeout = new_timeout;
}
void CButton::setClickTimeout(uint16_t new_timeout) {
	_click_timeout = new_timeout;
}
void CButton::setStepTimeout(uint16_t step_timeout) {
	_step_timeout = step_timeout;
}
void CButton::setType(bool type) {
	flags.type = type;
	if (!flags.noPin) {
		if (type) pinMode(_PIN, INPUT);
		else pinMode(_PIN, INPUT_PULLUP);
	}	
}
void CButton::setDirection(bool dir) {
	flags.inv_state = dir;
}
void CButton::setTickMode(bool tickMode) {
	flags.tickMode = tickMode;
}

// ==================== IS ====================
boolean CButton::isPress() {
	if (flags.tickMode) CButton::tick();
	if (flags.isPress_f) {
		flags.isPress_f = false;
		return true;
	} else return false;
}
boolean CButton::isRelease() {
	if (flags.tickMode) CButton::tick();
	if (flags.isRelease_f) {
		flags.isRelease_f = false;
		return true;
	} else return false;
}
boolean CButton::isClick() {	
	if (flags.tickMode) CButton::tick();
	if (flags.isOne_f) {
		flags.isOne_f = false;
		return true;
	} else return false;
}
boolean CButton::isHolded() {
	if (flags.tickMode) CButton::tick();
	if (flags.isHolded_f) {
		flags.isHolded_f = false;
		return true;
	} else return false;
}
boolean CButton::isHold() {
	if (flags.tickMode) CButton::tick();
	if (flags.step_flag) return true;
	else return false;
}
boolean CButton::state() {
	if (flags.tickMode) CButton::tick();
	return btn_state;
}
boolean CButton::isSingle() {
	if (flags.tickMode) CButton::tick();
	if (flags.counter_flag && last_counter == 1) {
		last_counter = 0;
		flags.counter_flag = false;
		return true;
	} else return false;
}
boolean CButton::isDouble() {
	if (flags.tickMode) CButton::tick();
	if (flags.counter_flag && last_counter == 2) {
		flags.counter_flag = false;
		last_counter = 0;
		return true;
	} else return false;
}
boolean CButton::isTriple() {
	if (flags.tickMode) CButton::tick();
	if (flags.counter_flag && last_counter == 3) {
		flags.counter_flag = false;
		last_counter = 0;
		return true;
	} else return false;
}
boolean CButton::hasClicks() {
	if (flags.tickMode) CButton::tick();
	if (flags.counter_flag) {
		flags.counter_flag = false;
		return true;
	} else return false;
}
uint8_t CButton::getClicks() {
	byte thisCount = last_counter;
	last_counter = 0;
	return thisCount;	
}
uint8_t CButton::getHoldClicks() {
	if (flags.tickMode) CButton::tick();
	return flags.hold_flag ? last_hold_counter : 0;	
}
boolean CButton::isStep(byte clicks) {
	if (flags.tickMode) CButton::tick();
	if (btn_counter == clicks && flags.step_flag && (millis() - btn_timer >= _step_timeout)) {
		btn_timer = millis();		
		return true;
	}
	else return false;
}

void CButton::resetStates() {
	flags.isPress_f = false;
	flags.isRelease_f = false;
	flags.isOne_f = false;
	flags.isHolded_f = false;
	flags.step_flag = false;
	flags.counter_flag = false;
	last_hold_counter = 0;
	last_counter = 0;
}

// ==================== TICK ====================
void CButton::tick(boolean state) {
	flags.mode = true;
	btn_state = state ^ flags.inv_state;
	CButton::tick();
	flags.mode = false;
}

void CButton::tick() {	
	// читаем пин
	if (!flags.mode && !flags.noPin) btn_state = !digitalRead(_PIN) ^ (flags.inv_state ^ flags.type);
	
	uint32_t thisMls = millis();
	
	// нажатие
	if (btn_state && !btn_flag) {
		if (!flags.btn_deb) {
			flags.btn_deb = true;
			btn_timer = thisMls;
		} else {
			if (thisMls - btn_timer >= _debounce) {
				btn_flag = true;			
				flags.isPress_f = true;
				flags.oneClick_f = true;
			}
		}    
	} else {
		flags.btn_deb = false;
	}

	// отпускание
	if (!btn_state && btn_flag) {
		btn_flag = false;
		if (!flags.hold_flag) btn_counter++;
		flags.hold_flag = false;
		flags.isRelease_f = true;
		btn_timer = thisMls;
		if (flags.step_flag) {
			last_counter = 0;
			btn_counter = 0;
			flags.step_flag = false;	
		}		
		if (flags.oneClick_f) {
			flags.oneClick_f = false;
			flags.isOne_f = true;
		}
	}

	// кнопка удерживается
	if (btn_flag && btn_state && (thisMls - btn_timer >= _timeout) && !flags.hold_flag) {
		flags.hold_flag = true;
		last_hold_counter = btn_counter;
		//btn_counter = 0;
		//last_counter = 0;
		flags.isHolded_f = true;
		flags.step_flag = true;
		flags.oneClick_f = false;
		btn_timer = thisMls;
	}

	// обработка накликивания
	if ((thisMls - btn_timer >= _click_timeout) && (btn_counter != 0)) {    
		last_counter = btn_counter;
		btn_counter = 0;
		flags.counter_flag = true;
	}
}

void CButton::Tick(void)
{
	if (CButton::first != nullptr)
	{
		CButton::button = CButton::first;
		CButton::button->tick();

		do
		{
			CButton::button = CButton::button->next;
			CButton::button->tick();

		} while ((button->next != nullptr));
	}
}