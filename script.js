myInput = document.getElementById('myInput')
myInput.value = Number(0)


IncBtn = document.getElementById('IncrementBtn')
DecBtn = document.getElementById('DecrementBtn')
ResetBtn = document.getElementById('ResetBtn')

IncBtn.onclick = function(){
    myInput.value = Number(myInput.value) + 1
}
DecBtn.onclick = function(){
    myInput.value = Number(myInput.value) - 1
}
ResetBtn.onclick = function(){
    myInput.value = Number(0)
}