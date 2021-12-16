func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
  var med1,med2 float64

  if len(nums1)!=0 {
    if len(nums1)%2==1 {
      med1=float64(nums1[len(nums1)/2])
    } else {
      med1=float64(nums1[len(nums1)/2-1]+nums1[len(nums1)/2])/float64(2)
    }
  }

  if len(nums2)!=0 {
    if len(nums2)%2==1 {
      med2=float64(nums2[len(nums2)/2])
    } else {
      med2=float64(nums2[len(nums2)/2-1]+nums2[len(nums2)/2])/float64(2)
    }
  }

  if len(nums1)==0 {
    med1=med2
  }
  if len(nums2)==0 {
    med2=med1
  }
  return (med1+med2)/2
}
