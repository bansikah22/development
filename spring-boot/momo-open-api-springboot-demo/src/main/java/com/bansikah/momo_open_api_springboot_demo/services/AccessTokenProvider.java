package com.bansikah.momo_open_api_springboot_demo.services;

import com.bansikah.momo_open_api_springboot_demo.client.MomoApiAuthClient;
import com.bansikah.momo_open_api_springboot_demo.payload.AccessTokenResponse;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;
import java.util.Base64;

@Service
public class AccessTokenProvider {

    private final MomoApiAuthClient authClient;

    @Value("${mtn.momo.user-id}")
    private String userId;

    @Value("${mtn.momo.api-key}")
    private String apiKey;

    @Value("${mtn.momo.subscription-key}")
    private String subscriptionKey;

    public AccessTokenProvider(MomoApiAuthClient authClient) {
        this.authClient = authClient;
    }

    public String getAccessToken() {
        String basicAuthHeader = "Basic " +
                Base64.getEncoder().encodeToString((userId + ":" + apiKey).getBytes());

        AccessTokenResponse resp = authClient.getAccessToken(basicAuthHeader, subscriptionKey, "{}");
        return resp.getAccessToken();
    }
}
