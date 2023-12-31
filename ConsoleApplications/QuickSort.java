import java.util.Arrays;
import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int[] array = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        quicksort(array,0,array.length - 1);

        for (int num : array) {
            System.out.print(num + " ");
        }
    }
    private static void quicksort(int[] array, int lowIndex, int maxIndex) {

        if (lowIndex >= maxIndex) return;

        int pivot = array[maxIndex];
        int leftPointer = lowIndex;
        int rightPointer = maxIndex;

        while (leftPointer < rightPointer) {

            while (array[leftPointer] <= pivot && leftPointer < rightPointer) {
                leftPointer++;
            }
            while (array[rightPointer] >= pivot && leftPointer < rightPointer) {
                rightPointer--;
            }
            swap(array,leftPointer,rightPointer);
        }
        swap(array,leftPointer,maxIndex);
        quicksort(array,lowIndex,leftPointer - 1);
        quicksort(array,leftPointer + 1,maxIndex);
    }

    private static void swap(int[] array,int leftPointer,int rightPointer) {
        int temp = array[leftPointer];
        array[leftPointer] = array[rightPointer];
        array[rightPointer] = temp;
    }
}