package com.bansikah.momo_open_api_springboot_demo;

import io.swagger.v3.oas.annotations.OpenAPIDefinition;
import io.swagger.v3.oas.annotations.info.Info;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@OpenAPIDefinition(info = @Info(title = "MoMo API", version = "1.0", description = "MTN MoMo Remittance Demo"))
@SpringBootApplication
@EnableFeignClients(basePackages = "com.bansikah.momo_open_api_springboot_demo.client")
public class MomoOpenApiSpringbootDemoApplication {
	public static void main(String[] args) {
		SpringApplication.run(MomoOpenApiSpringbootDemoApplication.class, args);
	}
}