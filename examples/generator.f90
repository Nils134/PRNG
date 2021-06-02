

program SimpleIO
   implicit none
   character(100) :: line
   real*8 COST
   integer(kind = 4) :: longval
   ! we'll loop over until user enters a negative number
   do
      ! this reads the input as a double-pricision value
      read(*,'(A)') line
      if (len_trim(line)==0) continue
      longval = 0
      do while( longval < 100000)
      CALL RANDOM_NUMBER(COST)
      Print "(f14.12)", COST
      longval = longval + 1
      end do 
   end do
   print '("Thank you!")'
   
end program SimpleIO