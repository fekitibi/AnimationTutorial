#ifndef _H_DRAW_
#define _H_DRAW_

#include "IndexBuffer.h"

enum class DrawMode {
	Points,
	LineStrip,
	LineLoop,
	Lines,
	Triangles,
	TriangleStrip,
	TriangleFan
};

// Draw using index buffer(EBO)
void Draw(IndexBuffer& inIndexBuffer, DrawMode mode);
// Draw without using an index buffer(EBO)
void Draw(unsigned int vertexCount, DrawMode mode);
// Draw geometry a number of times specified with the instanceCount using an index buffer(EBO)
void DrawInstanced(IndexBuffer& inIndexBuffer,
	DrawMode mode, unsigned int instanceCount);
// Draw geometry a number of times specified with the instanceCount without using an index buffer(EBO)
void DrawInstanced(unsigned int vertexCount,
	DrawMode mode, unsigned int numInstances);

#endif