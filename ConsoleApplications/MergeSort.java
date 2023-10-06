import java.util.*;


public class MergeSort {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int[] array = Arrays.stream(input.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[] sorted = mergeSort(array);

        for (int i : sorted) {
            System.out.print(i + " ");
        }
    }
    private static int[] mergeSort(int[] array) {

        if (array.length == 1) {
           return array;
        }

        int middleIndex = array.length / 2;

       int[] left = getSubArray(array,0,middleIndex);
       int[] right = getSubArray(array,middleIndex, array.length);
       int[] leftSorted = mergeSort(left);
       int[] rightSorted = mergeSort(right);
       return merge(leftSorted,rightSorted);
    }

    private static int[] getSubArray(int[] array, int startInclusive, int middleIndex) {
        int[] subArray = new int[middleIndex - startInclusive];
        for (int i = startInclusive,j = 0; i < middleIndex; i++,j++) {
            subArray[j] = array[i];
        }
        return subArray;
    }

    public static int[] merge(int[] left,int[] right) {
        int[] result = new int[left.length + right.length];
        int l = 0;
        int r = 0;
        int counter = 0;
        for (; l < left.length && r < right.length;counter++) {

            if (left[l] < right[r]) {
                result[counter] = left[l];
                l++;

            } else {
                result[counter] = right[r];
                r++;
            }
        }

        if (l == left.length) {
            for (; r < right.length; r++,counter++) {
                result[counter] = right[r];
            }
        } else {
            for (; l < left.length; l++,counter++) {
                result[counter] = left[l];
            }
        }
        return result;
    }
}