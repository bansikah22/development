package com.bansikah.momo_open_api_springboot_demo.config;

import com.bansikah.momo_open_api_springboot_demo.services.AccessTokenProvider;
import feign.RequestInterceptor;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
@RequiredArgsConstructor
public class MomoApiConfig {

    private final AccessTokenProvider provider;

    @Value("${mtn.momo.environment}")
    private String environment;

    @Value("${mtn.momo.subscription-key}")
    private String subscriptionKey;

    @Bean
    public RequestInterceptor momoAuthInterceptor() {
        return template -> template
                .header("Authorization", "Bearer " + provider.getAccessToken())
                .header("X-Target-Environment", environment)
                .header("Ocp-Apim-Subscription-Key", subscriptionKey);
    }
}
