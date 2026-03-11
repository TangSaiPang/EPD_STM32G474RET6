#ifndef __BSP_EPD_H
#define __BSP_EPD_H

#include <stdint.h>

#define SPI_HARDWARE		1
#define NSS_HARDWARE		1

#define RES_PIN				GPIO_PIN_2
#define DC_PIN				GPIO_PIN_1
#define BUSY_PIN			GPIO_PIN_11
#define EPD_GPIO_Port		GPIOB
#define	RES_SET()			HAL_GPIO_WritePin(EPD_GPIO_Port, RES_PIN, GPIO_PIN_SET)
#define RES_RESET()			HAL_GPIO_WritePin(EPD_GPIO_Port, RES_PIN, GPIO_PIN_RESET)
#define	DC_SET()			HAL_GPIO_WritePin(EPD_GPIO_Port, DC_PIN, GPIO_PIN_SET)
#define DC_RESET()			HAL_GPIO_WritePin(EPD_GPIO_Port, DC_PIN, GPIO_PIN_RESET)
#define EPD_BUSY()			HAL_GPIO_ReadPin(EPD_GPIO_Port,BUSY_PIN)

#define OLED_W   122
#define OLED_H   250

#define ROTATE_0            0   //屏幕正向显示
#define ROTATE_90           90  //屏幕旋转90度显示
#define ROTATE_180          180 //屏幕旋转180度显示
#define ROTATE_270          270 //屏幕旋转270度显示


#define WHITE          0xFF   //显示白色
#define BLACK          0x00   //显示黑色

typedef struct {
    uint8_t *Image;
    uint16_t Width;
    uint16_t Height;
    uint16_t WidthMemory;
    uint16_t HeightMemory;
    uint16_t Color;
    uint16_t Rotate;
    uint16_t WidthByte;
    uint16_t HeightByte;
} PAINT;
extern PAINT Paint;

//#define
//#define
//#define
//#define
//#define

void EPD_GPIO_Init(void);
void EPD_WR_Bus(uint8_t dat);
void EPD_WR_REG(uint8_t reg);
void EPD_WR_Byte(uint8_t dat);
void Epaper_READBUSY(void);
void EPD_Update(void);
void EPD_Init(void);
void Paint_NewImage(uint8_t *image,uint16_t Width,uint16_t Height,uint16_t Rotate,uint16_t Color);
void Paint_SetPixel(uint16_t Xpoint,uint16_t Ypoint,uint16_t Color);
void EPD_Clear(uint16_t Color);
void EPD_DrawPoint(uint16_t Xpoint,uint16_t Ypoint,uint16_t Color);
void EPD_Display(unsigned char *Image);
void EPD_DrawLine(uint16_t Xstart,uint16_t Ystart,uint16_t Xend,uint16_t Yend,uint16_t Color);
void EPD_DrawRectangle(uint16_t Xstart,uint16_t Ystart,uint16_t Xend,uint16_t Yend,uint16_t Color,uint8_t mode);
void EPD_DrawCircle(uint16_t X_Center,uint16_t Y_Center,uint16_t Radius,uint16_t Color,uint8_t mode);
void EPD_ShowChar(uint16_t x,uint16_t y,uint16_t chr,uint16_t size1,uint16_t color);
void EPD_ShowString(uint16_t x,uint16_t y,uint8_t *chr,uint16_t size1,uint16_t color);
uint32_t EPD_Pow(uint16_t m,uint16_t n);
void EPD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint16_t len,uint16_t size1,uint16_t color);
void EPD_ShowChinese(uint16_t x,uint16_t y,uint16_t num,uint16_t size1,uint16_t color);
void EPD_ShowPicture(uint16_t x,uint16_t y,uint16_t sizex,uint16_t sizey,const uint8_t BMP[],uint16_t Color);

#endif
