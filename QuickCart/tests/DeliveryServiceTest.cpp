#include <gtest/gtest.h>

#include "models/Delivery.hpp"
#include "models/DeliveryPartner.hpp"
#include "services/DeliveryService.hpp"

TEST(DeliveryServiceTest, AssignDeliveryToAvailablePartner)
{
    Delivery delivery(501, 101, 1);
    DeliveryPartner partner(1, "Alex", "9876543210");
    DeliveryService service;

    EXPECT_TRUE(service.assignDelivery(delivery, partner));
    EXPECT_FALSE(partner.isAvailable());

    EXPECT_EQ(delivery.getStatus(), DeliveryStatus::Assigned);
}


TEST(DeliveryServiceTest, CompleteDeliveryRestoresPartnerAvailability)
{
    Delivery delivery(501, 101, 1);
    DeliveryPartner partner(1, "Alex", "9876543210");
    DeliveryService service;

    ASSERT_TRUE(service.assignDelivery(delivery, partner));

    EXPECT_TRUE(
        service.updateDeliveryStatus(delivery, partner, DeliveryStatus::InTransit)
    );

    EXPECT_TRUE(
        service.updateDeliveryStatus(delivery, partner, DeliveryStatus::Delivered)
    );

    EXPECT_EQ(delivery.getStatus(), DeliveryStatus::Delivered);
    EXPECT_TRUE(partner.isAvailable());
}


TEST(DeliveryServiceTest, RejectInvalidStatusTransition)
{
    Delivery delivery(501, 101, 1);
    DeliveryPartner partner(1, "Alex", "9876543210");
    DeliveryService service;

    ASSERT_TRUE(service.assignDelivery(delivery, partner));

    EXPECT_FALSE(
        service.updateDeliveryStatus(delivery, partner, DeliveryStatus::Assigned)
    );

    EXPECT_EQ(delivery.getStatus(), DeliveryStatus::Assigned);
}