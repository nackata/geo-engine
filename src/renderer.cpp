#include "../include/renderer.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

bool Renderer::init(int width, int height, std::string title)
{
    if(!glfwInit()) return false;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
//    glfwWindowHint(GLFW_SAMPLES, 4);



    GLFWwindow * wind = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (wind == nullptr)
    {
        std::cerr << "error creating window" << std::endl;
        glfwTerminate();
        return false;
    }



    this->window = wind;

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glViewport(0, 0, width, height);

    mainShader = Shader("common/shaders/vertex_shader.glsl", "common/shaders/fragment_shader.glsl");

    mainShader.use();

    glm::mat4 projection(1.0);
    projection = glm::perspective(45.0f, (static_cast <float> (width) / static_cast <float> (height)), 0.1f, 100.0f);

    mainShader.setMat4("projection", projection);


    mainShader.setVec3("dirLight.ambient", 0.1, 0.1, 0.1);
    mainShader.setVec3("dirLight.diffuse", 0.3, 0.3, 0.3);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_MULTISAMPLE);


    return true;
}

void Renderer::drawScene()
{
    mainShader.use();

    // Calculating delta of time per frame

    double time = glfwGetTime();

    delta = time - lastFrame;
    lastFrame = time;

    // Setting view matrix for shader

    glm::mat4 view = cam->getView();

    mainShader.setMat4("view", view);

    // Setting up light

    // -- setting direction light direction in view coordinates

    mainShader.setBool("isDirLight", dirLight);

    if (dirLight)
    {
        mainShader.setVec3("dirLight.direction",
                        glm::vec3(cam->getViewRotation() *
                        glm::vec4(directionDirLight, 1.0)));
    }

    // --setting point lights

    mainShader.setInt("light_amount", phongLights.size());


    for (int i = 0; static_cast<size_t>(i) < phongLights.size() && i < POINT_LIGHTS; ++i)
    {
        std::string lightName = "pointLights[" + std::to_string(i) + "]";;
        mainShader.setVec3(lightName + ".position", glm::vec3(view * glm::vec4(phongLights[i]->position(), 1.0)));
        mainShader.setVec3(lightName + ".ambient", phongLights[i]->ambient());
        mainShader.setVec3(lightName + ".diffuse", phongLights[i]->diffuse());
        mainShader.setVec3(lightName + ".specular", phongLights[i]->specular());
        mainShader.setFloat(lightName + ".constant", phongLights[i]->constant());
        mainShader.setFloat(lightName + ".linear", phongLights[i]->linear());
        mainShader.setFloat(lightName + ".quadratic", phongLights[i]->quadratic());
    }

    // setting background color

    glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // rendering

    for (Object * ob : objects)
    {
        ob->model.Draw(mainShader);
    }

    glfwPollEvents();
}



