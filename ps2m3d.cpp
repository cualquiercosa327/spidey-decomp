#include "ps2m3d.h"


// @SMALLTODO
void M3d_BuildTransform(CSuper* a){
	a->actualcsuperend = (__int16*)69;
}

// @BIGTODO
void M3d_Render(void*)
{
	printf("void M3d_Render(void*)");
}

// @MEDIUMTODO
void DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)
{
    printf("DCModel_RenderModel(SModel const *,DCModelData *,matrix4x4 const *,void const *)");
}

// @MEDIUMTODO
void DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)
{
    printf("DC_PSXModel_RenderModel(SModel const *,matrix4x4 const *,void const *,DCModelData *)");
}

// @MEDIUMTODO
void M3d_PreprocessPulsingColours(i32)
{
    printf("M3d_PreprocessPulsingColours(i32)");
}

// @MEDIUMTODO
void M3d_PreprocessWibblyTextures(i32)
{
    printf("M3d_PreprocessWibblyTextures(i32)");
}

// @MEDIUMTODO
void M3d_RenderBackground(void *)
{
    printf("M3d_RenderBackground(void *)");
}

// @MEDIUMTODO
void M3d_RenderCleanup(void)
{
    printf("M3d_RenderCleanup(void)");
}

// @MEDIUMTODO
void M3d_RenderSetup(SCamera *,SViewport *,u32 *)
{
    printf("M3d_RenderSetup(SCamera *,SViewport *,u32 *)");
}

// @MEDIUMTODO
void RenderSuperItem(CItem *,bool)
{
    printf("RenderSuperItem(CItem *,bool)");
}
