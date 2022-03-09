#ifndef _H_ATTRIBUTE_
#define _H_ATTRIBUTE_

#include <vector>

template<typename T>
class Attribute {
protected:
	// Handle or ID
	unsigned int mHandle;
	// How much data the attribute contains
	unsigned int mCount;

private:
	// Disable copy and assignment operator, since attributers are living on GPU
	Attribute(const Attribute& other);
	Attribute& operator=(const Attribute& other);

	// This method will be implemented for all type of attributes
	void SetAttribPointer(unsigned int slot);

public:
	Attribute();
	~Attribute();

	// Uploads an array of data to the GPU
	void Set(T* inputArray, unsigned int arrayLength);
	void Set(std::vector<T>& input);
	// Bind unbind attributes from bind slots defined in the shader
	void BindTo(unsigned int slot);
	void UnBindFrom(unsigned int slot);
	// Getters for mCount and mHandle
	unsigned int Count();
	unsigned int GetHandle();
};

#endif