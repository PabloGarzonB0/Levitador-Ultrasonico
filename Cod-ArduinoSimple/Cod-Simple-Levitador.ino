byte TP = 0b10101010; // Para que cada puerto reciba una señal invertida
void setup() {
 
//Se define DDRC para habilitar las salidas analogicas
  DDRC = 0b11111111;

// Se inicializa timer 
  
noInterrupts(); // Uso para que el codigo tenga prioridad

TCCR1A = 0;

TCCR1B = 0;

TCNT1 = 0;

OCR1A = 200; // Se hace comparacion con el regristro (16MHz / 200 = 80kHz onda cuadrada -> 40kHz onda completa)

TCCR1B |= (1 << WGM12); // CTC mode

TCCR1B |= (1 << CS10); // Colocar el prescaler en 1 ==> no prescalado

TIMSK1 |= (1 << OCIE1A); // Habilitar comparacion por interrupcion de timer

interrupts(); // Activo interrupciones

}

ISR(TIMER1_COMPA_vect) {

PORTC = TP; // Envio el valor de TP a las salidas

TP = ~TP; // Invierto la señal de TP para el siguiente ciclo

}

void loop() {

// De momento en el loop no hay nada

}
