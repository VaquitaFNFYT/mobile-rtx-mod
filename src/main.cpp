#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(RTXPlayLayer, PlayLayer) {
    cocos2d::CCGLProgram* m_rtxShader = nullptr;

    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects)) return false;

        auto resources = Mod::get()->getResourcesDir();
        std::string vertPath = (resources / "rtx_vert.glsl").string();
        std::string fragPath = (resources / "rtx_frag.glsl").string();

        m_rtxShader = new cocos2d::CCGLProgram();
        if (m_rtxShader->initWithVertexShaderFilename(vertPath.c_str(), fragPath.c_str())) {
            m_rtxShader->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
            m_rtxShader->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
            m_rtxShader->link();
            m_rtxShader->updateUniforms();
        }

        return true;
    }

    void draw() {
        if (m_rtxShader) {
            m_rtxShader->use();
            m_rtxShader->setUniformLocationWith2f(
                m_rtxShader->getUniformLocationForName("u_lightPos"), 0.5f, 0.5f
            );
            m_rtxShader->setUniformLocationWith3f(
                m_rtxShader->getUniformLocationForName("u_lightColor"), 1.0f, 0.8f, 0.5f
            );
        }
        PlayLayer::draw();
    }
};
