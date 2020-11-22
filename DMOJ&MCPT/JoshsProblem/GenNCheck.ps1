for($i = 3; $i -lt 11; $i++){
    .\gen
    echo "Generated Data"
    # .\brute
    # echo "Ran Brute Force"
    .\JoshsProblem
    echo "Ran Intended"
    $a = cat "sol.out"
    $freq = [regex]::matches($a,"T").count
    # diff (cat brute.out) (cat sol.out)
    # echo "Diff ^"
    echo $freq
    mv "data.in" "data/data.$i.in"
    mv "sol.out" "data/data.$i.out"
}

# Case 4: 0 'T'