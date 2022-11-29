class Solution {
    public boolean searchMatrix(int[][] matrix, int x) {
        int n = matrix.length;
        int m = matrix[0].length;
        if (matrix.length == 0) {
            return false;
        }

        int low = 0, high = (n * m) - 1;

        while (low <= high) {

            int mid = (low + high) / 2;
            if (matrix[mid / m][mid % m] == x) {
                return true;
            }

            if (matrix[mid / m][mid % m] < x) {

                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
}