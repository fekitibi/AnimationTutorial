#ifndef _H_SHADER_
#define _H_SHADER_

#include <map>
#include <string>

class Shader {
private:
	// Shader ID
	unsigned int mHandle;
	// Attribute mao(string for attribute name and unsigned int for attribute, uniform ID)
	std::map<std::string, unsigned int> mAttributes;
	std::map<std::string, unsigned int> mUniforms;

	// The copy constructor and assignment operator is disabled, since shaders are not designed to be copied
	Shader(const Shader&);
	Shader& operator=(const Shader&);

	// Read shader code from file
	std::string ReadFile(const std::string& path);
	// Complie vertex shader source code and returns handle(ID)
	unsigned int CompileVertexShader(
		const std::string& vertex);
	// Complie fragment shader source code and return handle(ID)
	unsigned int CompileFragmentShader(
		const std::string& fragment);
	// Links vertex and fragment shader to a shader program
	bool LinkShaders(unsigned int vertex,
		unsigned int fragment);
	// The following methods will fill the uniforma and attribute maps
	void PopulateAttributes();
	void PopulateUniforms();

public:
	Shader();
	Shader(const std::string& vertex,
		const std::string& fragment);
	~Shader();

	// Loads, vertex, fragment shader code
	void Load(const std::string& vertex,
		const std::string& fragment);
	// Bind shader program to the GPU
	void Bind();
	// Unbind shader program from the GPU
	void UnBind();
	// Get attribute fr4om the map based on its name
	unsigned int GetAttribute(const std::string& name);
	// Get uniform fr4om the map based on its name
	unsigned int GetUniform(const std::string& name);
	// Getter for shader handle(ID)
	unsigned int GetHandle();
};

#endif
