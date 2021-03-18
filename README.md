# MTG Deck Converter

Converts Magic the Gathering deck from *.dck* to *.cod*

### Compiling with MinGW

In a terminal, go to the repository folder

`cd repo_folder`

Compile with

`g++ -o Main -I ../include *.cpp`

To convert de deck, run the *Main* output, indicating the name of the deck to convert and the name of the deck converted, in both names specify the extension of the file

`./Main deck_to_convert.cdk deck_converted.cod`

### Pending features

-- Conversion from *.cod* to *.dck*

-- Add support for partner commanders 