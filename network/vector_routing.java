import java.util.Scanner;

public class vector_routing {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("\nEnter the number of nodes : ");
        int numberOfNodes = scanner.nextInt();
        int[][] costMatrix = new int[numberOfNodes][numberOfNodes];
        int[][] routingTable = new int[numberOfNodes][numberOfNodes];
        int count = 0;

        System.out.println("\nEnter the cost matrix :\n");
        for (int i = 0; i < numberOfNodes; i++) {
            for (int j = 0; j < numberOfNodes; j++) {
                costMatrix[i][j] = scanner.nextInt();
                costMatrix[i][i] = 0;
                routingTable[i][j] = costMatrix[i][j];
            }
        }

        do {
            count = 0;
            for (int i = 0; i < numberOfNodes; i++) {
                for (int j = 0; j < numberOfNodes; j++) {
                    for (int k = 0; k < numberOfNodes; k++) {
                        if (routingTable[i][j] > costMatrix[i][k] + routingTable[k][j]) {
                            routingTable[i][j] = routingTable[i][k] + routingTable[k][j];
                            count++;
                        }
                    }
                }
            }
        } while (count != 0);

        for (int i = 0; i < numberOfNodes; i++) {
            System.out.println("\n\nState value for router " + (i + 1) + " is");
            for (int j = 0; j < numberOfNodes; j++){
                System.out.print("\nnode " + (j + 1) + " via " + (routingTable[i][j] + 1) + " Distance " + routingTable[i][j]);
            }
        }
    }
}