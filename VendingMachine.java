package machin;


	import java.util.ArrayList;

	public class VendingMachine {

	       ArrayList<Product> products;// list of products

	       int totalCoins;// total coins made

	       public VendingMachine() {
	                	
	                               
	    	   products = new ArrayList<Product>();
	    	   totalCoins = 0;

	       }

	       public void addProduct(Product p) {

	    	   products.add(p);

	       }

	       public boolean buyProduct(int id, int coins) {

	    	   int index = getProductIndex(id);

	    	   if (index != -1) {

	    		   if (products.get(index).getQuantity() > 0)
	    		   {

	    			   if (products.get(index).getPrice() <= coins)
	    			   {

	    				   products.get(index).buy();// buying
	                                                                                
	    				   totalCoins += coins;// updating coins

	    				   return true;

	    			   }
	    		   }

	    	   }

	                             

	    	   return false;

	       }


	       	public void reStock(int id, int newQuantity) {

	       		int index = getProductIndex(id);

	       		if (index != -1) {

	       			products.get(index).setQuantity(newQuantity);

	       			}

	       	}
	       	
	       	public int getRevenue()
	       	{

	       		return totalCoins;
	                			
	       	}

	       	public void resetRevenue() {

	       		totalCoins = 0;

	                }


	       	public int getProductIndex(int id) {

	       		for (int i = 0; i < products.size(); i++) {

	       			if (products.get(i).getId() == id) {
	       				return i;

	       			}

	       		}

	       		return -1;

	       	}

	               
	       	public String getProductMenu() {

	       		String menu = "Available Products--->\n";

	       		menu += String.format("%10s %15s %10s %10s\n", "ID", "NAME", "PRICE","QUANTITY");

	       		for (Product p : products) {

	       			menu += String.format("%10d %15s %10.2f %10d\n", p.getId(),

	       					p.getName(), p.getPrice(), p.getQuantity());

	       		}

	       		return menu;

	       	}

	}
