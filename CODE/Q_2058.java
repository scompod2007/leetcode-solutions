class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] result = {Integer.MAX_VALUE, 0};
        
        int firstCriticalIndex = -1;
        int lastCriticalIndex = -1;
        
        int currentIndex = 0;
        while (head.next != null && head.next.next != null) {
            int previousValue = head.val;
            int currentValue = head.next.val;
            int nextValue = head.next.next.val;
            
            boolean isLocalMinimum = currentValue < previousValue && currentValue < nextValue;
            boolean isLocalMaximum = currentValue > previousValue && currentValue > nextValue;
            
            if (isLocalMinimum || isLocalMaximum) {
                if (lastCriticalIndex == -1) {
                    firstCriticalIndex = currentIndex;
                    lastCriticalIndex = currentIndex;
                } else {
                    result[0] = Math.min(result[0], currentIndex - lastCriticalIndex);
                    lastCriticalIndex = currentIndex;
                    result[1] = Math.max(result[1], lastCriticalIndex - firstCriticalIndex);
                }
            }
            
            head = head.next;
            currentIndex++;
        }
        
        if (firstCriticalIndex == lastCriticalIndex) {
            return new int[] {-1, -1};
        }
        
        return result;
    }
}