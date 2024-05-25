#pragma once
#include "imgui_impl_glfw.h"
#include "emu/components/cpu.hpp"

class Window{
public:
    Window();
    ~Window();

    void display(CPU &cpu_t, RAM &mem_t);

private:
    GLFWwindow *m_window;
    bool m_show_window = true;

    void render(CPU &cpu_t, RAM &mem_t);
    void render_widgets(CPU &cpu_t, RAM &mem_t);

    void m_initialize_glfw();
    void m_initialize_imgui();
};