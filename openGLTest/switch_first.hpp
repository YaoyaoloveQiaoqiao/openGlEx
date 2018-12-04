////
////  hello_triangle_indexed.hpp
////  openGLTest
////
////  Created by yaoyao on 2018/11/8.
////  Copyright © 2018年 yaoyao. All rights reserved.
////
//
//#include <stdio.h>
//#include <iostream>
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include "stb_image.h"
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
////void Shader::setMat4(const std::string& name, float value[]) const {
////    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, value);
////}
////const char *vertexShaderSourceTexture = "#version 330 core\n"
////"layout (location = 0) in vec3 aPos;\n"
////"layout (location = 1) in vec3 aColor;\n"
////"layout (location = 2) in vec2 aTexCoord;\n"
////"out vec3 ourColor;\n"
////"out vec2 TexCoord;\n"
////"void main()\n"
////"{\n"
////"   gl_Position = vec4(aPos, 1.0);\n"
////"   ourColor = aColor;\n"
////"   TexCoord = aTexCoord;\n"
////"}\0";
////const char *fragmentShaderSourceTexture = "#version 330 core\n"
////"out vec4 FragColor;\n"
////"in vec3 ourColor;\n"
////"in vec2 TexCoord;\n"
////"uniform sampler2D ourTexture;\n"
////"void main()\n"
////"{\n"
////"   FragColor = texture(ourTexture, TexCoord);\n"
////"}\n\0";
//
//// settings
//
//
//int transformEx(){
//    using std::cout;    using std::endl;
//    glfwInit();
//    //    主版本
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    //    次版本
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    //    告诉glfw 我们使用的是core_profile 核心模块
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//    //    向前兼容
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//    //    创建一个GLFW 窗口   宽 高  窗口名字  后边两个暂时不用管
//    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    //    通知GLFW将我们窗口的上下文设置为当前线程的主上下文了
//    glfwMakeContextCurrent(window);
//    
//    //    GLAD 是用来管理openGL 的函数指针的。所以在调用任何openGL函数之前我们都需要初始化GLAD。
//    //    我们给GLAD传入了用来加载系统相关的OpenGL函数指针地址的函数。GLFW给我们的是glfwGetProcAddress，它根据我们编译的系统定义了正确的函数。
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//    //    创建渲染的视口: 我们必须要告诉OpenGl 需要渲染的尺寸大小，即为视口 viewport(),这样openGL 才能知道根据窗口大小显示数据和坐标。
//    //    glViewport 前两个参数控制视口左下角位置，后两个参数控制视口的宽和高
//    //    openGL 幕后使用的是glViewport 定义的 位置和宽高进行2D转换
//    glViewport(0, 0, 800, 600);
//    //    窗口调整的时候 视口应该也被调整  对窗口注册一个回调函数每次窗口大小被调整的时候会被调用
//    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
//    
//    
//    //   通过 glfwSetFramebufferSizeCallback glfw 函数 当窗口frame 变化时会调用。
//    //    对于视网膜屏 Retain 屏   宽度和高度明显比原输入值更高一点。
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    
//    
//    //Test
//    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
//    glm::mat4 trans;
//    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));  //从这里就能看出单位矩阵的作用了。初始化的trans是一个单位矩阵，让它平移到(1.0f, 1.0f, 0.0f)的位置产生了一个平移矩阵。
//    vec = trans * vec;
//    std::cout << "(" << vec.x << "," << vec.y << "," << vec.z << ")" << std::endl;
//    
//    //build and compile shader program
//    //--------------------------------
//    //vertex shader
//    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSourceTexture, NULL);
//    glCompileShader(vertexShader);
//    
//    // check for shader compile errors
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    // fragment shader
//    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSourceTexture, NULL);
//    glCompileShader(fragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    // link shaders
//    int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    // check for linking errors
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//    
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        //位置                  // 颜色                 //纹理坐标
//        0.5f,   0.5f,   0.0f,   1.0f,   0.0f,   0.0f,   1.0f,   1.0f,   //右上角
//        0.5f,   -0.5f,  0.0f,   0.0f,   1.0f,   0.0f,   1.0f,   0.0f,   //右下角
//        -0.5f,  -0.5f,  0.0f,   0.0f,   0.0f,   1.0f,   0.0f,   0.0f,   //左下角
//        -0.5f,  0.5f,   0.0f,   1.0f,   1.0f,   0.0f,   0.0f,   1.0f    //左上角
//        
//    };
//    
//    unsigned int indices[] = {
//        0, 1, 3,
//        1, 2, 3
//    };
//    
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    glGenBuffers(1, &EBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindVertexArray(VAO);
//    
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//    
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//    
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    //
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true);
//    unsigned char* data = stbi_load("beauty.jpg", &width, &height, &nrChannels, 0);
//    if (data) {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//        std::cout << "aa" << std::endl;
//    stbi_image_free(data);
//    
//    glm::mat4 trans1;
//    trans = glm::scale(trans1, glm::vec3(0.5f, 0.5f, 0.5f));
//    trans = glm::rotate(trans1, /*glm::radians(90.0f)*/(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
//    
//    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    
//    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//    glBindVertexArray(0);
//    
//    
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    
//    
//    
//    
//    void processInput(GLFWwindow *window);
//    
//    //   为了防止 渲染的图像一出现就退出 我们使用while 循环 。我们可以称之为Render Loop
//    //    glfwWindowShouldClose 每次循环开始前检查一次GLFW 是否被要求退出 是true 的话渲染便结束了。
//    while(!glfwWindowShouldClose(window))
//    {
//        //输出控制
//        processInput(window);
//        //        glfwSwapBuffers 会交换颜色缓冲（他是存储着GLFW 窗口每一个像素色值的大缓冲），将会作为输出显示在屏幕上
//        //        当程序退出的时候 使用一个自定义的颜色清空屏幕  在每个新的渲染迭代可是的时候我们总希望清屏否则总是看到上次渲染的结果。
//        //        我们可以使用glClear   GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。 我们清空颜色 。
//        glClearColor(0.5f, 0.1f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transform"), 1, GL_FALSE, glm::value_ptr(trans1));
//
//        // draw our first triangle
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        // glBindVertexArray(0); // no need to unbind it every time
//        
//        glfwSwapBuffers(window);
//        //        glfwPollEvents 检查函数有没有触发什么事件 键盘输入 鼠标移动 并调用对应函数
//        glfwPollEvents();
//    }
//    
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//    
//    glfwTerminate();
//    
//    return 0;
//}
//
//
////void framebuffer_size_callback(GLFWwindow* window, int width, int height)
////{
////    glViewport(0, 0, width, height);
////}
////void processInput(GLFWwindow *window)
////{
////    //
////    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
////        glfwSetWindowShouldClose(window, true);
////}
//
//
//
