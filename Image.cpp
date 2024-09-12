#include "Image.h"
#include "validate.h"
#include "dcshellutils.h"
#include "PCTex.h"
#include "dcfileio.h"
#include "mem.h"


u16 gSlicedImageRelated[16];

// @Ok
Image::~Image(void)
{
}

// @Ok
SlicedImage2::SlicedImage2(
		void* pData,
		i32 width,
		i32 height,
		i32 slicew,
		i32 sliceh,
		u8 a7,
		u16 a8,
		u32 a9)
{
	print_if_false(width >= 2 && width <= 640, "Unlikely width for SlicedImage2");
	print_if_false(height >= 0 && height <= 480, "Unlikely height for SlicedImage2");

	print_if_false(slicew >= 0 && slicew <= 256, "Unlikely slicew for SlicedImage2");
	print_if_false(sliceh >= 0 && sliceh <= 256, "Unlikely sliceh for SlicedImage2");

	if (a7 == 8)
	{
		width >>= 1;
	}

	u8 v11;
	if (a7 == 4)
	{
		v11 = 2;
	}
	else
	{
		v11 = a7 == 8;
	}

	this->field_1C = v11;
	this->field_10 = a9;

	if ( a7 == 8 )
	{
		this->field_18 = PCTex_CreateTexture256(
				width,
				height,
				pData,
				0,
				a9,
				"SlicedImage2",
				0,
				0);
	}
	else if ( a7 == 4 )
	{
		this->field_18 = PCTex_CreateTexture16(
				width,
				height,
				pData,
				0,
				"SlicedImage2",
				0,
				0,
				1);
	}
	else
	{
		error("Invalid slicedimage color depth.");
	}

	if (a9 & 8)
	{
		Bitmap256* pBitmap = new Bitmap256(
				reinterpret_cast<char*>(pData),
				gSlicedImageRelated,
				width,
				height,
				this->field_18);
		PCTex_SetTextureUserData(this->field_18, pBitmap);
	}

	this->field_16 = height;
	this->field_14 = width >> this->field_1C;
	
}

// @Ok
SlicedImage2::~SlicedImage2(void)
{
	if (this->field_18)
	{
		PCTex_ReleaseTexture(this->field_18, true);
	}
}

// @SMALLTODO
void SlicedImage2::UnknownSlicedImageVirtualFunc(void)
{
	printf("void SlicedImage2::UnknownSlicedImageVirtualFunc(void)");
}

// @Ok
// @Matching
void SlicedImage2::setData(void* pData)
{
	PCTex_ReleaseTexture(this->field_18, 1);

	i32 texture;
	if (this->field_1C == 1)
		texture = PCTex_CreateTexture256(
			2 * this->field_14,
			this->field_16,
			pData,
			0,
			this->field_10,
			"SlicedImage2",
			0,
			0);
	else
		texture = PCTex_CreateTexture16(
			this->field_14 << this->field_1C,
			this->field_16,
			pData,
			0,
			"SlicedImage2",
			0,
			0,
			1);
	this->field_18 = texture;
	if (this->field_10 & 8)
	{
		Bitmap256* pBit = new Bitmap256(
			reinterpret_cast<char*>(pData),
			gSlicedImageRelated,
			this->field_14 << this->field_1C,
			this->field_16,
			this->field_18);

		PCTex_SetTextureUserData(this->field_18, pBit);
	}
}

// @SMALLTODO
void SlicedImage2::draw(i32, i32, i32, float)
{
	printf("void SlicedImage2::draw(i32, i32, i32, float)");
}

// @Ok
INLINE i32 GetBMPBitDepth(char* pData)
{
	u16* buf = reinterpret_cast<u16*>(pData);
	i32 depth = buf[14];

	print_if_false(depth == 4 || depth == 8, "Unrecognized color depth %d", depth);
	return depth;
}

// @MEDIUMTODO
void Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)
{
    printf("Load4BitBMP_2(char *,char **,i32 *,i32 *,u16 *)");
}

// @Ok
i32 LoadNBitBMP_(
		char* a1,
		char** a2,
		i32* a3,
		i32* a4,
		u16* a5,
		i32* a6)
{

	i32 fileSize = FileIO_Open(a1);
	if (fileSize <= 0)
	{
		error("\nFile %s not found", a1);
		return 0;
	}

	print_if_false(fileSize > 16, "screwy BMP file size");

	u16* pBmp = static_cast<u16*>(DCMem_New(fileSize, 1, 1, 0, 1));
	if (pBmp)
	{
		FileIO_Load(pBmp);
		FileIO_Sync();

		*a6 = GetBMPBitDepth(reinterpret_cast<char*>(pBmp));

		if (*a6 == 4)
		{
			Load4BitBMP_2(reinterpret_cast<char*>(pBmp), a2, a3, a4, a5);
		}
		else
		{
			Load8BitBMP2(reinterpret_cast<char*>(pBmp), a2, a3, a4, a5, 0);
		}

		Mem_Delete(pBmp);
		return 1;
	}

	error("\nNot enough memory to load %s", a1);
	return 0;
}

// @Ok
// @Matching
SlicedImage2::SlicedImage2(void)
{
    printf_fancy("stubbed: SlicedImage2::SlicedImage2");
}

// @Ok
INLINE Image::Image(void)
{
	this->field_4 = 0;
	this->field_5 = 0;
	this->field_6 = 0;
	this->field_7 = 0x80;
	this->field_8 = 0x80;
	this->field_9 = 0x80;
	this->field_A = 0;
	this->field_B = 0;
	this->field_C = 4096;
}

// @Ok
int SlicedImage2::screenHeight(void)
{
	return (this->field_C * this->field_16) >> 12;
}

// @Ok
int Load8BitBMP_2(char *a1, char **a2, int *a3, int *a4, unsigned __int16 *a5)
{
	Load8BitBMP2(a1, a2, a3, a4, a5, false);
	return 1;
}

void validate_SlicedImage2(void)
{
	VALIDATE_SIZE(SlicedImage2, 0x20);

	VALIDATE(SlicedImage2, field_10, 0x10);

	VALIDATE(SlicedImage2, field_14, 0x14);
	VALIDATE(SlicedImage2, field_16, 0x16);
	VALIDATE(SlicedImage2, field_18, 0x18);
	VALIDATE(SlicedImage2, field_1C, 0x1C);

	VALIDATE_VTABLE(SlicedImage2, UnknownSlicedImageVirtualFunc, 1);
	VALIDATE_VTABLE(SlicedImage2, setData, 2);
	VALIDATE_VTABLE(SlicedImage2, draw, 3);
}

void validate_Image(void)
{
	VALIDATE(Image, field_4, 0x4);
	VALIDATE(Image, field_5, 0x5);
	VALIDATE(Image, field_6, 0x6);
	VALIDATE(Image, field_7, 0x7);
	VALIDATE(Image, field_8, 0x8);
	VALIDATE(Image, field_9, 0x9);
	VALIDATE(Image, field_A, 0xA);
	VALIDATE(Image, field_B, 0xB);
	VALIDATE(Image, field_C, 0xC);
}
