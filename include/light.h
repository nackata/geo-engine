#pragma once

#include <glm/glm.hpp>

#include <vector>
#include <string>

class Light
{
    glm::vec3 pos{0.0, 0.0, 0.0};

    glm::vec3 amb{0.0, 0.0, 0.0};
    glm::vec3 dif{1.0, 1.0, 1.0};
    glm::vec3 spec{0.5, 0.5, 0.5};

    float con = 1.0;
    float lin = 0.009;
    float quad = 0.0032;
public:

    void setPosition(glm::vec3 pos) { this->pos = pos; }
    void setPosition(float x, float y, float z) { this->pos = glm::vec3(x, y, z); }

    glm::vec3 position() { return this->pos; }

    void setAmbient(glm::vec3 amb) { this->amb = amb; }
    void setAmbient(float r, float g, float b) { this->amb = glm::vec3(r, g, b); }

    glm::vec3 ambient() { return this->amb; }

    void setDiffuse(glm::vec3 dif) { this->dif = dif; }
    void setDiffuse(float r, float g, float b) { this->dif = glm::vec3(r, g, b); }

    glm::vec3 diffuse() { return this->dif; }

    void setSpecular(glm::vec3 spec) { this->spec = spec; }
    void setSpecular(float r, float g, float b) { this->spec = glm::vec3(r, g, b); }

    glm::vec3 specular() { return this->spec; }

    void setConst(float constant) {this->con = constant; }

    float constant() {return con;}

    void setLinear(float lin) {this->lin = lin; }

    float linear() {return lin; }

    void setQuadratic(float quadratic) {this->quad = quadratic; }

    float quadratic() { return quad; }


    Light() {}
};
