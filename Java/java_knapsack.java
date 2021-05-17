import java.util.Scanner;

public class java_knapsack {
  
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Knapsack Problem...\nEnter number of items: ");
    int numberOfItems = sc.nextInt();
    System.out.print("Enter maximum weight of the container: ");
    int maxWeight = sc.nextInt();
    int randomProfit[] = new int[numberOfItems];
    int randomWeight[] = new int[numberOfItems];
    int ascendingProfit[] = new int[numberOfItems];
    int ascendingWeight[] = new int[numberOfItems];
    int descendingProfit[] = new int[numberOfItems];
    int descendingWeight[] = new int[numberOfItems];
    System.out.println("Random Order");
    System.out.print("Enter weights for " + numberOfItems + " items in random order(Spaces in betweeen): ");
    for (int i = 0; i < numberOfItems; i++) {
      randomWeight[i] = sc.nextInt();
    }
    System.out.print("Enter profits for corresponding " + numberOfItems + " items(Spaces in betweeen): ");
    for (int i = 0; i < numberOfItems; i++) {
      randomProfit[i] = sc.nextInt();
    }
    double randomTotal = fractionalKnapsack(randomProfit, randomWeight, maxWeight);
    System.out.println("Total Profit: " + randomTotal);  
  }
  
  public static double fractionalKnapsack(int profit[], int weight[], int maxWeight) {
    double profitPerWeight[] = new double[profit.length];
    int maxPW = -1;
    double totalProfit = 0;
    int j;
    for (int i = 0; i < profit.length; i++) {
      profitPerWeight[i] = (double)profit[i] / (double)weight[i];  
    }
    while (true) {
      j = 0;
      while (j < profit.length) {
        if (weight[j] > 0) {
          maxPW = j;
          break;
        }
        j++;
      }
      if (j == profit.length) {
        break; 
      }
      for (int i = j + 1; i < profit.length; i++) {
        if (profitPerWeight[i] > profitPerWeight[maxPW] && weight[i] > 0) {
          maxPW = i; 
        }        
      }      
      if (weight[maxPW] <= maxWeight) {
        maxWeight -= weight[maxPW];
        totalProfit += profit[maxPW];
        weight[maxPW] = 0;
        if (maxWeight == 0) {
          break;
        }
      } else {
        totalProfit += maxWeight * profitPerWeight[maxPW];
        break;
      }
    }
    return totalProfit;
  }
  
}
