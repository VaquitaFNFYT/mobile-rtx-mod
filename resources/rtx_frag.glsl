precision mediump float;

varying vec2 v_texCoord;
uniform sampler2D CC_Texture0;

uniform mediump vec2 u_lightPos;
uniform lowp vec3 u_lightColor;

void main() {
    vec4 baseColor = texture2D(CC_Texture0, v_texCoord);
    
    if (baseColor.a < 0.05) {
        gl_FragColor = baseColor;
        return;
    }

    vec2 lightDir = u_lightPos - v_texCoord;
    float distSq = dot(lightDir, lightDir);
    float attenuation = 1.0 / (1.0 + distSq * 20.0);
    vec3 finalRGB = baseColor.rgb + (u_lightColor * attenuation * 0.8);
    
    gl_FragColor = vec4(finalRGB, baseColor.a);
}
