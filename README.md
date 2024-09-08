# Final-difference

```
start
    initialize (input, parsedInput)

    receive input

    parse input:
        if input is invalid:
            throw error
        else:
            parsedInput = parse(input)
        endif

     compute
        initialize (endLoop = false, listOfDifferences, currentSequence, finalCommonDifference)

        while (!endLoop):
            if currentSequence == 0:
                     gather all differences of parsedInput
            else:
                 gather all differences of listOfDifferences at currentSequence
              endif


             if differences is empty:
                  endLoop = true
                 stopLooping
             endif

              if all differences are the same:
                   endLoop = true
                    finalCommonDifference = differences[0];
                   stop looping
              else:
                 currentSequence += 1
                 Add key of currentSequence to listOfDifferences
                 Add value of differences to the added key of listOfDifferences.
               endif
        endwhile
      if finalCommonDifference has value:
            OUTPUT(finalCommonDifference)
       else:
             OUTPUT(Error or did not converge)
      endif
end
```
