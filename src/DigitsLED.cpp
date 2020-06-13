#include <DigitsLED.hpp>

void CDigitLED::begin()
{
    this->num_leds = NUM_LEDS;
    this->line_length = LEDS_AT_LINE;

    FastLED.addLeds<WS2812B, LED_DATA_PIN, GRB>(this->leds, this->num_leds);
    FastLED.setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(100);

    this->begined = true;
}

void CDigitLED::drawString(String str, CRGB color)
{
    this->led_pointer = 0;
    
    for(int i = str.length() - 1; i >= 0; i--){
        draw(str[i], color);
    }

    FastLED.show();
}

void CDigitLED::draw(char c, CRGB color)
{
  switch (c)
  {
  case '0':
    drawZero(color);
    break;
  case '1':
    drawOne(color);
    break;
  case '2':
    drawTwo(color);
    break;
  case '3':
    drawThree(color);
    break;
  case '4':
    drawFour(color);
    break;
  case '5':
    drawFive(color);
    break;
  case '6':
    drawSix(color);
    break;
  case '7':
    drawSeven(color);
    break;
  case '8':
    drawEight(color);
    break;
  case '9':
    drawNine(color);
    break;
  case ':':
    drawDb(color);
    break;
  case '-':
    drawBlind();
  }
}

void CDigitLED::drawZero(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
}
void CDigitLED::drawOne(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawTwo(CRGB color)
{
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 5);
    this->led_pointer += this->line_length * 5;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawThree(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawFour(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length *2);
    this->led_pointer += this->line_length * 2;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawFive(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length );
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawSix(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 4);
    this->led_pointer += this->line_length * 4;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawSeven(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawEight(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 7);
    this->led_pointer += this->line_length * 7;
}

void CDigitLED::drawNine(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 4);
    this->led_pointer += this->line_length * 4;
}

void CDigitLED::drawDb(CRGB color)
{
    fill(color, this->led_pointer, this->led_pointer + 4);
    this->led_pointer += 4;
}

void CDigitLED::drawBlind(void)
{
  fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 7);
  this->led_pointer += this->line_length * 7;
}

void CDigitLED::fill(CRGB color, uint start, uint end) {
    for(int i = start; i < end; this->leds[i++] = color);
}


void CDigitLED::drawString(String str, Effect color)
{
    this->led_pointer = 0;
    
    for(int i = str.length() - 1; i >= 0; i--){
        draw(str[i], color);
    }

    FastLED.show();
}


void CDigitLED::draw(char c, Effect color)
{
  switch (c)
  {
  case '0':
    drawZero(color);
    break;
  case '1':
    drawOne(color);
    break;
  case '2':
    drawTwo(color);
    break;
  case '3':
    drawThree(color);
    break;
  case '4':
    drawFour(color);
    break;
  case '5':
    drawFive(color);
    break;
  case '6':
    drawSix(color);
    break;
  case '7':
    drawSeven(color);
    break;
  case '8':
    drawEight(color);
    break;
  case '9':
    drawNine(color);
    break;
  case ':':
    drawDb(color);
    break;
  }
}

void CDigitLED::drawZero(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
}
void CDigitLED::drawOne(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawTwo(Effect color)
{
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 5);
    this->led_pointer += this->line_length * 5;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawThree(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawFour(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length *2);
    this->led_pointer += this->line_length * 2;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawFive(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length );
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawSix(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 4);
    this->led_pointer += this->line_length * 4;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
}

void CDigitLED::drawSeven(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length * 3);
    this->led_pointer += this->line_length * 3;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
}

void CDigitLED::drawEight(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 7);
    this->led_pointer += this->line_length * 7;
}

void CDigitLED::drawNine(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 2);
    this->led_pointer += this->line_length * 2;
    fill(CRGB(0, 0, 0), this->led_pointer, this->led_pointer + this->line_length);
    this->led_pointer += this->line_length;
    fill(color, this->led_pointer, this->led_pointer + this->line_length * 4);
    this->led_pointer += this->line_length * 4;
}

void CDigitLED::drawDb(Effect color)
{
    fill(color, this->led_pointer, this->led_pointer + 4);
    this->led_pointer += 4;
}

void CDigitLED::fill(Effect color, uint start, uint end) {
    color(this->leds, start, end);
}

CButton::CButton(int pin): pin(pin)
{
  if (CButton::first == nullptr)
    CButton::first = this;
  else
    CButton::last->next = this;

  CButton::last = this;
}

bool CButton::isPressed()
{
  return false;
}

bool CButton::isReleased()
{
  return false;
}

void CButton::update()
{
  Serial.println("Updates button");
}

void CButton::Tick()
{
  if (CButton::first != nullptr)
  {
    CButton::button = CButton::first;
    CButton::button->update();

    do
    {
      CButton::button = CButton::button->next;
      CButton::button->update();

    } while ((button->next != nullptr));
  }
}

CButton* CButton::last = nullptr;
CButton* CButton::first = nullptr;
CButton* CButton::button = nullptr;

CDigitLED DigitLED;