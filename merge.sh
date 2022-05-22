
for dir in */
do
    if [[ "$dir" != "Lab1/" ]]
    then
        echo $dir
        cd $dir
        pdfunite title.pdf report.pdf final.pdf
        cd ..
    fi
done