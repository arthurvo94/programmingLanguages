PROGRAM p3

!!! Specifications !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

IMPLICIT NONE

!!! Declare Variables

INTEGER :: status, numCities, i, j, bestDistance, permutations
CHARACTER(20) :: filename
CHARACTER(20), ALLOCATABLE :: cityList(:)
INTEGER, ALLOCATABLE :: bestPath(:), table(:,:), path(:)

!!! Execution !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

! prompt and read filename from user input
WRITE (*, '(1x,A,/,1x)', ADVANCE="NO") "Enter File Name:  "
READ *, filename

! open file, check for errors
OPEN(UNIT=15, FILE=filename, STATUS="OLD", ACTION="READ", IOSTAT=status)
IF(status /= 0) THEN
    PRINT *, "File did not open correctly!"
    STOP
END IF

! read numCities and allocate arrays
READ(15, FMT=100) numCities
! WRITE (*, '(1x,A,I4,/)', ADVANCE="NO") "Number of cities: ", numCities


! allocate arrays 
ALLOCATE(cityList(1:numCities))
ALLOCATE(table(1:numCities,1:numCities))
ALLOCATE(bestPath(1:numCities))
ALLOCATE(path(1:numCities))

! read city names and distances and add to table
DO i = 1, numCities
    READ(15,'(A)') cityList(i)
    path(i)=i
    DO j = 1, numCities
        READ(15, FMT=100) table(i,j)
    END DO
END DO

! initialize values
bestDistance = 2147483647
permutations = 0
bestPath = 0

CALL PERMUTE(2, numCities)

!   Report best path and distances
DO i = 1, numCities
    IF (i == numCities) THEN
        PRINT '(1X,A,A,A,A,I8,A)', trim(cityList(bestPath(i))), " to ", &
        trim(cityList(1)), " -- ", table(bestPath(i), 1), " miles"
    ELSE
        PRINT '(1X,A,A,A,A,I8,A)', trim(cityList(bestPath(i))), " to ", &
        trim(cityList(bestPath(i + 1))), " -- ", table(bestPath(i), bestPath(i + 1)), " miles"
    END IF
END DO

PRINT '(1X,A,I8,A)', "Best distance is: ", bestDistance, " miles"
! PRINT '(1X, A, I8)', "Number of permutations is: ", permutations

!   Clean up
CLOSE(15)
DEALLOCATE(cityList)
DEALLOCATE(table)
DEALLOCATE(bestPath)
DEALLOCATE(path)


100 FORMAT (I6)

!   Inner subroutine
CONTAINS

RECURSIVE SUBROUTINE PERMUTE(first, last)
INTEGER :: i, currentDistance, first, last

! Base case
IF (first == last) THEN
    ! initialize distance from home city (1) to path (2)
    currentDistance = table(1, path(2))
    DO i = 2, (last - 1)
        !add to current distance the distance from path(i) to path(i+1)
        currentDistance = currentDistance + table(path(i), path(i+1))
    END DO
    !Get distance from last city back home
    !add to current distance the distance from path(last) to path(1)
    currentDistance = currentDistance + table(path(last), 1)

    ! save best path
    IF (currentDistance < bestDistance) THEN
        bestDistance = currentDistance
        DO i = 1, numCities
            bestPath(i) = path(i)
        END DO
    END IF

    ! print for testing
    ! DO i = 1, numCities
    !     IF(i == numCities) THEN
    !         PRINT '(1X,A,A,I8)', cityList(path(i)), cityList(1), table(path(i), 1)
    !     ELSE
    !         PRINT '(1X,A,A,I8)', cityList(path(i)), cityList(path(i+1)), table(path(i), path(i+1))
    !     END IF
    ! END DO
    ! PRINT '(1X, A, I8,/)', "Distance is: ", currentDistance

    permutations = permutations + 1
ELSE
    ! Mix it up
    DO i = first, last
        CALL SWAP(first, i)

        ! Recursion reduction step
        CALL PERMUTE(first + 1, last)

        CALL SWAP(first, i)
    END DO
END IF
    
END SUBROUTINE

SUBROUTINE SWAP(a, b)
    INTEGER :: a, b, temp
    
    temp = path(a)
    path(a) = path(b)
    path(b) = temp
END SUBROUTINE

END PROGRAM
