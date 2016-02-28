#version 410
precision highp float;

in vec3 interpPosition;
in vec3 interpNormal;

out vec4 fragColor;

vec3 lightPos = vec3(6.0, 4.0, -1.0);
vec3 ambientColor = vec3(0.1, 0.0, 0.0);
vec3 diffuseColor = vec3(0.5, 0.0, 0.0);
vec3 specColor = vec3(1.0, 1.0, 1.0);
float shininess = 16.0;
float screenGamma = 2.2;

void main() {
	
	vec3 normal = normalize(interpNormal);
	vec3 lightDir = normalize(lightPos - interpPosition);

	float lambertian = max(dot(lightDir,normal), 0.0);
	float specular = 0.0;

	if(lambertian > 0.0) {
		vec3 viewDir = normalize(-interpPosition);

		vec3 halfDir = normalize(lightDir + viewDir);
		float specAngle = max(dot(halfDir, normal), 0.0);
		specular = pow(specAngle, shininess);
	}
	vec3 colorLinear = ambientColor + lambertian * diffuseColor + specular * specColor;

	vec3 colorGammaCorrected = pow(colorLinear, vec3(1.0/screenGamma));

	fragColor = vec4(colorGammaCorrected, 1.0);
}