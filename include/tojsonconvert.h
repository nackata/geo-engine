#pragma once

#include <QJsonObject>
#include <glm/glm.hpp>

class ToJson
{
public:
    static QJsonObject vectorToObj(glm::vec3 vec) {

        QJsonObject vectorObj;

        vectorObj.insert("X", vec.x);
        vectorObj.insert("Y", vec.y);
        vectorObj.insert("Z", vec.z);

        return vectorObj;
    }

    static QJsonObject quatToObj(glm::quat quat) {

        QJsonObject quatObj;

        quatObj.insert("X", quat.x);
        quatObj.insert("Y", quat.y);
        quatObj.insert("Z", quat.z);
        quatObj.insert("W", quat.w);

        return quatObj;
    }

    static glm::vec3 objToVec(const QJsonObject & obj) {
        glm::vec3 vector;

        vector.x = obj.value("X").toDouble();
        vector.y = obj.value("Y").toDouble();
        vector.z = obj.value("Z").toDouble();

        return vector;
    }

    static glm::quat objToQuat(const QJsonObject & obj) {
        glm::quat quat;

        quat.x = obj.value("X").toDouble();
        quat.y = obj.value("Y").toDouble();
        quat.z = obj.value("Z").toDouble();
        quat.w = obj.value("W").toDouble();

        return quat;
    }

};
