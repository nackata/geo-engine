#version 330 core
struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
    vec3 diffColor;
};

struct DirLight
{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
};

struct PointLight
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

#define POINT_LIGHT 16
uniform PointLight pointLights[POINT_LIGHT];

uniform int light_amount;

in vec3 Normal;
in vec3 FragPos;

in vec2 TexCoord;

out vec4 FragColor;

uniform bool isDirLight;

uniform Material material;
uniform DirLight dirLight;

vec3 calcDirectionLight(DirLight dirLight, vec3 norm, vec3 viewDir);
vec3 calcPointLight(PointLight pointLight, vec3 norm, vec3 viewDir, vec3 fragPosition);

uniform sampler2D diffuse_map;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(-FragPos);

    vec3 result = vec3(0.0);

    if (dot(norm ,viewDir) < 0)
        norm = -norm;

    if (isDirLight)
    {
        result += calcDirectionLight(dirLight, norm, viewDir);
    }

    for (int i = 0; i < light_amount && i < POINT_LIGHT; ++i)
    {
        result += calcPointLight(pointLights[i], norm, viewDir, FragPos);
    }

    FragColor = vec4(result, 1.0);
}

vec3 calcDirectionLight(DirLight dirLight, vec3 norm, vec3 viewDir)
{
    vec3 lightDir = normalize(-dirLight.direction);

//    vec3 ambient = dirLight.ambient * vec3(texture(material.diffuse, TexCoord));
    vec3 ambient = dirLight.ambient * material.diffColor;

    // DIFFUSE
//    vec3 diffuse = dirLight.diffuse * max(dot(norm, lightDir), 0.0) * vec3(texture(material.diffuse, TexCoord));
    vec3 diffuse = dirLight.diffuse * max(dot(norm, lightDir), 0.0) * material.diffColor;

    return ambient + diffuse;
}

vec3 calcPointLight(PointLight pointLight, vec3 norm, vec3 viewDir, vec3 fragPosition)
{
    vec3 lightDir = normalize(pointLight.position - fragPosition);

    // ATTENUATION
    float distance = length(pointLight.position - fragPosition);
    float attenuation = 1.0 / (pointLight.constant + pointLight.linear * distance + pointLight.quadratic * (distance * distance));

    if (attenuation < 0.01) return vec3(0.0, 0.0, 0.0);

    // AMBIENT
//    vec3 ambient = pointLight.ambient * vec3(texture(material.diffuse, TexCoord));

    // DIFFUSE
//    vec3 diffuse = pointLight.diffuse * max(dot(norm, lightDir), 0.0) * vec3(texture(material.diffuse, TexCoord));
    vec3 diffuse = pointLight.diffuse * max(dot(norm, lightDir), 0.0) * material.diffColor;

    // SPECULAR
//    float specStr = 0.5;
//    vec3 spec = reflect(-lightDir, norm);
//    vec3 tex = material.diffColor;
//    vec3 specular = pow(max(dot(spec, viewDir), 0.0), 32) * pointLight.specular * tex;

    // RESULT
    return(0 + diffuse + 0) * attenuation;
}
