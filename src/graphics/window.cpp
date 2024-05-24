#include "emu/graphics/window.hpp"
#include "emu/components/ram.hpp"
#include "emu/graphics/glad.h"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include "imgui_memory_editor.h"


static MemoryEditor MEM_EDITOR;


Window::Window(){
    m_initialize_glfw();
    m_initialize_imgui();
}


Window::~Window(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}


void Window::m_initialize_glfw(){
    if(!glfwInit()){
        spdlog::error("Failed to initialize GLFW!");
        return;
    }
    spdlog::info("Starting up the Debug Interface...");

    glfwWindowHint(GLFW_DOUBLEBUFFER, 1);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    m_window = glfwCreateWindow(1024, 1024, "0x6502", NULL, NULL);
    if(!m_window){
        spdlog::error("Failed to create window!");
        return;
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        spdlog::error("Failed to initialize GLAD!");
    }
}


void Window::m_initialize_imgui(){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    

    if(!(ImGui_ImplGlfw_InitForOpenGL(m_window, true) && ImGui_ImplOpenGL3_Init())){
        spdlog::error("Failed to initialize ImGui!");
    }
}


void Window::display(CPU cpu_t, RAM mem_t){
  while(!glfwWindowShouldClose(m_window)){
    render(cpu_t, mem_t);
  }
}


void Window::render(CPU cpu_t, RAM mem_t){
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    render_widgets(cpu_t, mem_t);
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


    glfwSwapBuffers(m_window);
    glfwPollEvents();
}


void Window::render_widgets(CPU cpu_t, RAM mem_t){
    ImGui::ShowAboutWindow(&m_show_window);
    ImGui::ShowDemoWindow(&m_show_window);
    MEM_EDITOR.DrawWindow("RAM", mem_t.data, sizeof(mem_t.data));


    ImGui::Begin("CPU: Registries");
        ImGui::Text("Accumulator: (%d)",        cpu_t.registers.ACC);
        ImGui::Text("X: (%d)",                  cpu_t.registers.X);
        ImGui::Text("Y: (%d)",                  cpu_t.registers.Y);
        
        ImGui::Text("Break Command: (%d)",      cpu_t.registers.B);
        ImGui::Text("Carry Flag: (%d)",         cpu_t.registers.C);
        ImGui::Text("Decimal mode: (%d)",       cpu_t.registers.D);
        ImGui::Text("Interrupt Disable: (%d)",  cpu_t.registers.I);
        ImGui::Text("Negative Flag: (%d)",      cpu_t.registers.N);
        ImGui::Text("Overflow: (%d)",           cpu_t.registers.V);
        ImGui::Text("Zero Flag: (%d)",          cpu_t.registers.Z);
    ImGui::End();
}