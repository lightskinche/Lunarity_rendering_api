#include "main_h.h"

SDL_Window* wind;
VkDevice* gpu;
unsigned int count;
const char** instance_buf;
void** function_extens;
int main(void) {
	SDL_Init(SDL_INIT_VIDEO);
	wind = SDL_CreateWindow("Test", 0, 100, 640, 640, SDL_WINDOW_VULKAN);
	SDL_Vulkan_GetInstanceExtensions(wind, &count, NULL);

	instance_buf = calloc(count, sizeof(char*));
	function_extens = calloc(count, sizeof(void*));
	SDL_Vulkan_GetInstanceExtensions(wind, &count, instance_buf);

	for (int i = 0; i < count; ++i) 
		printf("%s\n", instance_buf[i]);
	
	VkInstanceCreateInfo info;
	info.enabledExtensionCount = count;
	info.ppEnabledExtensionNames = instance_buf;
	info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO, info.pNext = NULL, info.flags = 0, info.pApplicationInfo = NULL, info.enabledLayerCount = 0, info.ppEnabledLayerNames = NULL;
	VkInstance instance;
	VkResult result = vkCreateInstance(&info, NULL, &instance);
	printf("%d", result);

	SDL_Delay(1000);
	return 0;
}