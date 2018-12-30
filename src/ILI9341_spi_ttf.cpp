#include "ILI9341_spi_ttf.h"

//constructor
ILI9341_spi_ttf::ILI9341_spi_ttf(SPIClass *_spi) : ttfSpiFullColor(_spi) {};

//Rectangle setting required for drawing ILI9341
void ILI9341_spi_ttf::set_rect(uint16_t _x1, uint16_t _x2, uint16_t _y1, uint16_t _y2) {
  digitalWrite(this->Display_DC, LOW);
  spi->transfer(CMD_COLUMN_ADDRESS_SET);
  digitalWrite(this->Display_DC, HIGH);
  spi->transfer16(_x1);
  spi->transfer16(_x2);
  digitalWrite(this->Display_DC, LOW);
  spi->transfer(CMD_PAGE_ADDRESS_SET);
  digitalWrite(this->Display_DC, HIGH);
  spi->transfer16(_y1);
  spi->transfer16(_y2);
  digitalWrite(this->Display_DC, LOW);
  spi->transfer(CMD_MEMORY_WRITE);
  digitalWrite(this->Display_DC, HIGH);
}
