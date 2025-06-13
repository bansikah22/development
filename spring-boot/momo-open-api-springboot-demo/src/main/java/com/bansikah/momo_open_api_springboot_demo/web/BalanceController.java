package com.bansikah.momo_open_api_springboot_demo.web;

import com.bansikah.momo_open_api_springboot_demo.client.MomoApiClient;
import com.bansikah.momo_open_api_springboot_demo.config.MomoProperties;
import com.bansikah.momo_open_api_springboot_demo.dto.AccountBalanceDto;
import com.bansikah.momo_open_api_springboot_demo.services.AccessTokenProvider;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class BalanceController {

    private final AccessTokenProvider accessTokenProvider;
    private final MomoApiClient momoApiClient;
    private final MomoProperties momoProperties;

    public BalanceController(AccessTokenProvider accessTokenProvider,
                             MomoApiClient momoApiClient,
                             MomoProperties momoProperties) {
        this.accessTokenProvider = accessTokenProvider;
        this.momoApiClient = momoApiClient;
        this.momoProperties = momoProperties;
    }

    @GetMapping("/balance")
    public ResponseEntity<?> getBalance() {
        try {
            String accessToken = accessTokenProvider.getAccessToken();
            String bearerToken = "Bearer " + accessToken;
            String env = momoProperties.getEnvironment();
            String key = momoProperties.getSubscriptionKey();

            System.out.println("Calling MTN API with:");
            System.out.println("Authorization: " + bearerToken);
            System.out.println("X-Target-Environment: " + env);
            System.out.println("Ocp-Apim-Subscription-Key: " + key);

            AccountBalanceDto balance = momoApiClient.getAccountBalance(
                    bearerToken,
                    env,
                    key
            );

            System.out.println("Response: " + balance);

            return ResponseEntity.ok(balance);
        } catch (Exception e) {
            e.printStackTrace();
            return ResponseEntity.status(500).body("Error: " + e.getMessage());
        }
    }
}


