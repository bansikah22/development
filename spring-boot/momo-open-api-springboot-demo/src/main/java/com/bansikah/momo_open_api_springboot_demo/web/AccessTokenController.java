package com.bansikah.momo_open_api_springboot_demo.web;

import com.bansikah.momo_open_api_springboot_demo.services.AccessTokenProvider;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class AccessTokenController {

    private final AccessTokenProvider provider;

    public AccessTokenController(AccessTokenProvider provider) {
        this.provider = provider;
    }

    @GetMapping("/api/token")
    public String getToken() {
        return provider.getAccessToken();
    }
}
