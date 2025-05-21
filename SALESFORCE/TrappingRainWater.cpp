// CODE 360:  Trapping Rain Water

long long getTrappedWater(long long* arr, int n) {
    if(n==0) return 0;
    long long l,r;
    l=0;
    r=n-1;
    long long left_min_wall,right_min_wall;
    left_min_wall=right_min_wall=0;
    long long total=0;
    while(l<r)
    {
        if(arr[l]<=arr[r])
        {
            if(left_min_wall > arr[l])
            {
                total+=left_min_wall - arr[l];
            }
            else{
                left_min_wall=arr[l];
            }
            l++;
        }
        else{
            if(right_min_wall > arr[r])
            {
                total+= right_min_wall - arr[r];
            }
            else{
                right_min_wall=arr[r];
            }
            r--;
        }
    }
    return total;
}
//Time complexity:o(n)
//space complexity:o(1)
