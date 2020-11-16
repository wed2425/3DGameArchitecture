#pragma once
#include <string>
#include <vector>


#include "Object.h"
#include "FileManager.h"
#include "RenderableObject.h"
#include "glm/glm.hpp"
#include "include/GL/glew.h"

class RenderableObject;


class FileManager
{
public:
	static FileManager* instance()
	{
		static FileManager instance;

		return &instance;
	}

public:
	void loadObj(
		RenderableObject* target_obj,
		const char* obj_path,
		const char* texture_path,
		const char* vs_shader_path,
		const char* fs_shader_path
	);

	bool loadOBj(
		const char* path,
		std::vector<glm::vec3>& out_vertices,
		std::vector<glm::vec2>& out_uvs,
		std::vector<glm::vec3>& out_normals
	);

	GLuint loadDDS(const char* imagepath);

	GLuint loadBMP(const char* imagepath);


	GLuint loadShaders(const char* vertex_file_path, const char* fragment_file_path);


	
};