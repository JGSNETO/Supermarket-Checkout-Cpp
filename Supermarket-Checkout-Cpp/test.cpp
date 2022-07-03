#include "gtest/gtest.h"
#include "Checkout.h"

//TEST(CheckoutTests, CanInstanciateCheckout) {
//	Checkout co;
//}
class CheckoutTests : public ::testing::Test {	
public:

protected:
	Checkout checkOut;
};
//Text_F: Fixsture 
TEST_F(CheckoutTests, CanAddItemPrice) {
	//Checkout co;
	checkOut.addItemPrice("a", 1);

}

TEST_F(CheckoutTests, AddItems) {
	//Checkout co;
	checkOut.addItem("a");
}

TEST_F(CheckoutTests, CanCalculateTotal) {
	checkOut.addItemPrice("a", 1);
	checkOut.addItem("a");
	int total= checkOut.calculateTotal();
	ASSERT_EQ(1, total);
}

TEST_F(CheckoutTests, CanGetTotalForMultipleItems) {
	checkOut.addItemPrice("a", 1);
	checkOut.addItemPrice("b", 2);
	checkOut.addItem("a");
	checkOut.addItem("b");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(3, total);

}

TEST_F(CheckoutTests, CanAddDiscount) {
	checkOut.addDiscount("a", 3, 2); //Item, item count, discount price. 
}

TEST_F(CheckoutTests, CancalculateTotalWithDiscount) {
	checkOut.addItemPrice("a", 1);
	checkOut.addDiscount("a", 3, 2);
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(2, total);
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
	ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}