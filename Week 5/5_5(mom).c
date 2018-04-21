/**
 * Returns the minimum of two integers a, b
 */
long long minf(long long a, long long b) {
  return (a < b ? a : b);
}

/**
 * Swaps two integer variables, pointers to whom are a and b
 */
void swap(long long *a, long long *b) {
  long long temp = *a;
  *a = *b;
  *b = temp;
}

/**
 * Sorts the elements arr[l..r] in non-decreasing order
 */
void insertionSort(long long *arr, long long l, long long r) {
  long long i;
  for (i = l + 1; i <= r; i++) {
    long long key = arr[i], j = i - 1;
    while (j >= l && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

/**
 * Returns the nth smallest number in arr[l..r]
 */
long long getNthElement(long long *arr, long long l, long long r, long long n);

/**
 * Partitions the array arr[l..r] and returns an integer x such that
 * for all l <= i < x, arr[i] <= arr[x] and
 * for all x < i <= r, arr[x] < arr[i]
 *
 * The parameter use_custom_pivot enables the same function to be used in
 * quickSort and getNthElement
 * If its value is non zero, then the pivot value is considered to be the
 * parameter pivot. Else, the median of arr[l..r] is considered to be the pivot.
 */
long long partition(long long *arr, long long l, long long r, int use_custom_pivot, long long pivot) {
  long long arr_size = r - l + 1, i;
  if (use_custom_pivot == 0) {
    // Incase of even number of elements, obtain the smaller number 
    pivot = getNthElement(arr, l, r, (arr_size + 1) / 2);
  }
  // Find and swap the pivot with arr[r]
  for (i = l; i <= r; i++) {
    if (arr[i] == pivot) {
      swap(&arr[i], &arr[r]);
      break;
    }
  }

  // Perform the partitioning
  long long j;
  i = l - 1;
  for (j = l; j <= r; j++) {
    if (arr[j] <= pivot) {
      swap(&arr[j], &arr[i + 1]);
      ++i;
    }
  }
  return i;
}

/**
 * Returns the nth smallest number in arr[l..r]
 */
long long getNthElement(long long *arr, long long l, long long r, long long n) {
  long long arr_size = r - l + 1;
  if (arr_size == 1) {
    return arr[l];
  } else {
    long long i, num_bins = (arr_size / 5) + ((arr_size % 5) != 0);
    long long *temp_arr = malloc(sizeof(long long) * num_bins), temp_index = 0;
    
    // Compute the median of medians
    for (i = l; i <= r; i += 5) {
      long long j = minf(i + 4, r);
      insertionSort(arr, i, j);
      temp_arr[temp_index++] = arr[(i + j) / 2];
    }
    long long median_of_medians = getNthElement(temp_arr, 0, temp_index - 1, (temp_index + 1) / 2);
    free(temp_arr);

    // Partition with respect to the median of medians and decide what needs
    // to be done
    long long p = partition(arr, l, r, 1, median_of_medians);
    long long pivot_pos = p - l + 1;
    if (pivot_pos == n) {
      return arr[p];
    } else if (n < pivot_pos) {
      return getNthElement(arr, l, p - 1, n);
    } else {
      return getNthElement(arr, p + 1, r, n - pivot_pos);
    }
  }
}