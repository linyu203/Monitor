package main

import (
    "fmt"
    "os"
    io "bufio"
)
func main(){
    //fmt.Println("Monitor Project")
    args := os.Args
    if len(args) != 2 {
        fmt.Println("to run the app: ./app <filename>")
        return 
    }
    fileName := args[1]
    readFile, err := os.Open(fileName)
    if err != nil {
        fmt.Println("Open file failed, file name:", fileName)
        return 
    }
    fileScanner := io.NewScanner(readFile)
    fileScanner.Split(io.ScanLines)

    m := &Monitor{}
    m.Init()
    for fileScanner.Scan() {
        line := fileScanner.Text()
        ts := m.MparseLine(line)
        if len(ts)>0 {
            fmt.Println(ts, "Event :", line)
        }
    }
}
