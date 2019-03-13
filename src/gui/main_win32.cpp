#include <windows.h>
#include "common_main.hpp"

int CALLBACK WinMain(
  _In_ HINSTANCE hInstance,
  _In_ HINSTANCE hPrevInstance,
  _In_ LPSTR     lpCmdLine,
  _In_ int       nCmdShow
)
{
  astral::gui::start();
  return EXIT_SUCCESS;
}
