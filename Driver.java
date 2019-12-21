package machin;

import java.util.Scanner;

public class Driver {

                static Scanner scanner = new Scanner(System.in);

                static VendingMachine vendingMachine = new VendingMachine();


                static void fillInitialProducts() {

               Product p1 = new Product(1, "Pepsi", 2.0, 5);
            Product p2 = new Product(2, "Coke", 2.0, 4);

            Product p3 = new Product(3, "ThumbsUp", 1.0, 8);

            Product p4 = new Product(4, "SevenUp", 1.0, 5);

            Product p5 = new Product(5, "Mountain Dew", 1.0, 2);

            Product p6 = new Product(6, "Fizz", 2.0, 8);


            vendingMachine.addProduct(p1);

            vendingMachine.addProduct(p2);

            vendingMachine.addProduct(p3);

            vendingMachine.addProduct(p4);

            vendingMachine.addProduct(p5);

            vendingMachine.addProduct(p6);

                }

                public static void main(String[] args) {

                	int id = 0;

                	int coins;

                	fillInitialProducts();//filling initial products

                               

                	do {

                		System.out.println(vendingMachine.getProductMenu());

                         System.out.print("\nEnter the id of the product"+ " you want to buy(enter -1 to quit): ");

                         id = scanner.nextInt();

                  if (id != -1) {

                          if (vendingMachine.getProductIndex(id) == -1) {

                          System.out.println("Product with given id doesn't exist!");

                                                                } 
                          else {

                            System.out.print("Input coins: ");

                                 coins = scanner.nextInt();

                                    if (vendingMachine.buyProduct(id, coins)) 
                                    {

                                           System.out.println("Product bought successfully!");

                                      } 
                                    else {

                                               System.out.println("Insufficient coins " + "or Product out of stock");
                                          System.out.println("Dispensing " + coins  + " coins out!");//returning the coins

                                                           }

                                                  }

                                     }

                         } while (id != -1);


                   System.out.println("Total coins received: " + vendingMachine.getRevenue());

                }



}
