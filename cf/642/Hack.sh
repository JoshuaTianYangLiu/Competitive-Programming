for I in {1..200000}
do
    echo '1\n'$I>D.in
    ./D
    java DHack
    diff D.out DHack.out
done