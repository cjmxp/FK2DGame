/**
*	created:		2012-6-20   18:51
*	filename: 		WindowBitmap
*	author:			FreeKnight
*	Copyright (C): 	
*	purpose:		
*/
//------------------------------------------------------------------------
#pragma once
//------------------------------------------------------------------------
#include "CanvasCommon.h"
#include "StructCommon.h"
#include "../IFKCanvas.h"
//------------------------------------------------------------------------
class WBitmap : public IBitmap  
{
protected:
	void* m_pBmpStruct;
	void Destroy();
public:
	WBitmap();
	virtual ~WBitmap();
	void SetPos(int x, int y);
	void DrawRleFunc(int dx, int dy, int w, int h, BYTE* bits);
	//接口方法
public:
	//初始化函数
	virtual BOOL Create(int nWidth, int nHeight) ;									//创建位图
	virtual BOOL Create(int nWidth, int nHeight, void* ptr) ;						//给定数据区创建位图
	virtual BOOL Create(IBitmap* parent, int x, int y, int nWidth, int nHeight);	//从父位图上创建对象
	virtual IBitmap* SubBitmap(int x, int y, int nWidth, int nHeight) ;				//创建子位图
	virtual int GetWidth() const ;													//获得宽度
	virtual int GetHeight() const ;													//获得高度

	//绘图相关
	virtual BOOL Clear(WPixel clr, RECT* pRc = NULL) ;																			//清屏
	virtual BOOL Draw(int x, int y, IBitmap* bmp, DWORD dwStyle = BLIT_NORMAL) ;												//把别的位图绘制到此位图
	virtual void Draw(int x, int y, const char* s, WPixel clr) ;																//打印ASCII字符
	virtual BOOL Draw(int dx, int dy, int w, int h, IBitmap* bmp, int sx, int sy, DWORD dwStyle = BLIT_NORMAL);
	virtual BOOL DrawAlpha(int dx, int dy, IAlphaBitmap* bmp, DWORD dwStyle = BLIT_COPY);										//把别的位图绘制到此位图
	virtual BOOL DrawAlpha(int dx, int dy, int w, int h, IAlphaBitmap* bmp, int sx, int sy, DWORD dwStyle = BLIT_COPY);			//增强的AlphaDraw
	virtual BOOL DrawRle(int dx, int dy, IRleBitmap* bmp, DWORD dwStyle = BLIT_COPY);											//把别的rle位图绘制到此位图
	virtual BOOL DrawRle(int dx, int dy, IRleBitmap* bmp, BYTE* pPal, DWORD dwStyle = BLIT_COPY);								//把别的rle位图绘制到此位图
	virtual BOOL DrawRle(int dx, int dy, int w, int h, IRleBitmap* bmp, int sx, int sy, DWORD dwStyle = BLIT_COPY);				//增强的rle绘制
	virtual BOOL DrawRle(int dx, int dy, int w, int h, IRleBitmap* bmp, BYTE* pPal, int sx, int sy, DWORD dwStyle = BLIT_COPY); //增强的rle绘制

	virtual BOOL Blit2DC(HDC hDC,int dx,int dy,int x,int y,int w,int h)  ;														//BLIT 一个矩形部分到 DC
	virtual BOOL DrawBox(RECT& rc, WPixel clr, DWORD dwStyle = BLIT_NORMAL, int alpha = 255);									//绘制矩形盒

	virtual BOOL DrawLine(POINT& ptFrom, POINT& ptTo, WPixel clr, DWORD dwStyle = BLIT_NORMAL, int alpha = 255);				//绘制直线
	//其它
	virtual WPixel* operator[](int y)  const;																					//返回一个扫描行指针
	virtual void* GetBmpStruct() const {return m_pBmpStruct;}																	//返回数据
	virtual BOOL Load(void *bmpdata) ;																							//从数据区读出位图
	virtual BOOL Save(const char *filename) const ;																				//保存位图
	virtual void SetUserData(DWORD userdata) ;																					//设置用户数据
	virtual DWORD GetUserData() const ;																							//得到用户数据
	virtual BOOL IsValid() const;
	virtual void Release() ;
	virtual void SetData(void* pBmp){m_pBmpStruct = pBmp;}
	virtual BOOL Scroll(int x, int y);

	virtual BOOL DrawText(ITTFont*, int x, int y, const char* str, WPixel color, DWORD style=FONT_ALPHA);
	virtual BOOL DrawTextEx(ITTFont*, int x, int y, const char* str, WPixel color, WPixel outlinecolor, DWORD style=FONT_ALPHA);
	virtual BOOL IsTransparent(POINT& ptSelect);
	//从本位图上创建一个独立的Tile子位图(即菱形格位图, ptLeftTop为菱形格的左顶点)
	virtual IBitmap* SubTile(POINT ptLeftTop);
	virtual BOOL LoadEx(void* customdata);
	virtual DWORD GetSize(); // 得到图片所占内存的大小
	virtual BOOL DrawPixel(int x, int y, WPixel clr, DWORD dwStyle = BLIT_NORMAL, int alpha = 255);
	virtual BOOL DrawText(int x, int y, const char* str, WPixel color, DWORD style=FONT_ALPHA);	//输出点阵文字

	// 将IBitmap画向Canvas
	virtual BOOL Draw(ICanvas* pCanvas, int dx, int dy, DWORD dwStyle = BLIT_NORMAL);
	virtual BOOL Draw(ICanvas* pCanvas, int dx, int dy, int w, int h, int sx, int sy, DWORD dwStyle = BLIT_NORMAL);

	BOOL LoadJpeg(void* jpgdata, int size);
	BOOL SaveEx(const char *filename, int bpp) const;	//保存位图
};
//------------------------------------------------------------------------