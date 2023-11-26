#include <Adafruit_Thermal.h>

#define fsr1AnalogPin A0 // FSR is connected to analog 0
#define fsr2AnalogPin A1 // FSR is connected to analog 1
#define fsr3AnalogPin A2 // FSR is connected to analog 2

Adafruit_Thermal printer(&Serial1);

bool fsr1, fsr2, fsr3;
char *myStrings[] = {
"Your life line is strong and un-\nwavering, showing your resilien-\nce in the face of challenges.\nEmbrace your inner strength and\nlet it guide you.",
"The heart line reveals a deep\ncapacity for love and empathy.\nTrust your heart's wisdom, and\nit will lead you to meaningful\nconnections.",
"Your head line is clear and\nsharp, indicating a sharp intel-\nlect. Use your mind wisely to\nnavigate life's complex decisions.",
"The fate line is etched with\ntwists and turns, suggesting a\nunique and adventurous path.\nEmbrace the unpredictability of\nyour destiny.",
"A triangle on your lifeline\nforetells a powerful transforma-\ntion ahead. Embrace change, for\nit will lead to personal growth\nand fulfillment.",
"A fork at the end of your heart\nline indicates a choice between\ntwo paths in love. Listen to\nyour heart, and it will guide\nyou to the right one.",
"A strong sun line reveals a ra-\ndiant personality and charisma.\nShine your light to attract\npositivity and success.",
"The presence of a star on your\ndestiny line suggests a moment\nof great achievement.\nStay focused, and your dreams\nwill come true.",
"A square mark on your palm sig-\nnifies stability and grounding\nin your life.\nTrust in your ability to build\na strong foundation.",
"The mount of Venus is well-\ndeveloped, indicating a strong\nlove and passion for life.\nEmbrace your desires and enjoy\nthe pleasures of existence.",

"A cross on your palm represents\na period of transformation and\nspiritual growth.\nEmbrace this time of self-\ndiscovery and renewal.",
"The long fingers on your hand\nsuggest an analytical and\nthoughtful nature.\nUse your intellect to your ad-\nvantage in all your endeavors.",
"The fate line ends in a trident,\nsignifying success and recogni-\ntion in your chosen path.\nYour hard work will pay off\nhandsomely.",
"I see a unique and rare quality\nin your palm, a mark of a\nspecial destiny waiting to be\nfulfilled.",
"The star on your sun line indi-\ncates a moment of great accomp-\nlishment.\nTrust in your abilities, and \nyou'll achieve what you desire.",
"A circle on your palm suggests\na protective influence watching\nover you. You are safe and\nguided on your life's journey.",
"Your heart line is long and\ngently curving, revealing a\nloving and compassionate nature.\nShare your affection with those\naround you.",
"The mount of Jupiter is pronoun-\nced, showing leadership quali-\nties.Take charge of your life\nand guide it to success.",
"A diamond shape on your palm\nsignifies a period of abundance\nand good fortune. Stay open to\nblessings that come your way.",
"The head line is strong and\nunbroken, indicating a clear\nand rational mind.\nUse your intelligence to solve\nlife's challenges.",

"Your thumb is well-proportioned,\nindicating strong willpower and\ndetermination. You have the\npower to shape your destiny.",
"A ladder on your palm suggests\na climb to success through hard\nwork and dedication.\nKeep ascending with perseverance",
"A star on your mount of Saturn\nindicates a time of discipline\nand wisdom.\nYour responsibilities will lead\nto great achievements.",
"Your intuition is heightened,\nwith a clear fate line leading\nto your natural talents.\nTrust your instincts in\nimportant decisions.",
"The presence of a triangle on\nyour lifeline signifies a\npivotal moment in your life.\nEmbrace change, for it will\nbring growth and success.",
"Your palm shows signs of a sig-\nnificant life event approaching.\nEmbrace it with an open heart\nand mind, as it will lead to\npersonal growth.",
"The heart line is deeply etched,\nsymbolizing strong emotional\nconnections.\nNurture your relationships,\nfor they hold the key to\nhappiness.",
"A star on your sun line suggests\na period of recognition and\nsuccess.Stay true to your goals,\nand you'll shine brightly.",
"The mount of Venus is prominent,\nindicating a passionate and\naffectionate nature.\nShare your love and enjoy the\npleasures of life.",
"The lifeline is long and un-\nbroken, foretelling a healthy\nand long life.\nTake care of your well-being\nto make the most of it.",

"A cross on your palm reflects a\ntime of spiritual awakening and\nself-discovery. Embrace the\njourney of inner transformation.",
"The presence of a square on your\npalm symbolizes stability and\ngrounding in your life.\nTrust in your ability to create\na strong foundation.",
"Your fingers are long and slen-\nder, showing an analytical and\nperceptive mind.\nUse your intellect to navigate\nlife's challenges.",
"A trident at the end of your\nfate line signifies success and\nrecognition in your chosen path.\nYour hard work will be rewarded.",
"The mount of Luna is well-\ndeveloped, indicating a deep\nconnection to your intuition and\ndreams.\nListen to your inner guidance.",
"A circle on your palm represents\nprotection and guidance from\nhigher forces. You are safe and\nguided on your life's journey.",
"Your heart line is gentle and\ncurving, revealing a loving and\ncompassionate nature.\nShare your affection with those\nwho matter most.",
"The mount of Jupiter is promi-\nnent, signifying leadership\nqualities. Take charge of your\nlife and guide it to success.",
"A diamond shape on your palm\nsuggests a period of abundance\nand good fortune. Stay open to the\nblessings that come your way.",
"The head line is strong and\nclear, indicating a sharp and\nrational mind. Use your intellect\nto make wise decisions.",

"Your thumb is well-proportioned,\nshowcasing your strong willpower\nand determination. You have the\npower to shape your destiny.",
"A ladder on your palm suggests\na climb to success through hard\nwork and dedication.\nKeep ascending with perseverance",
"A star on your mount of Saturn\nsignifies a time of discipline\nand wisdom.\nYour responsibilities will lead\nto great achievements.",
"Your intuition is heightened,\nwith a clear fate line guiding\nyou towards your innate talents.\nTrust your instincts in crucial\ndecisions.",
"The presence of a triangle on\nyour lifeline suggests a signi-\nficant turning point in your\nlife. Embrace change, for it\nwill bring growth and success.",
"I see a powerful and creative\nenergy in your palm, expressed\nthrough your artistic talents\nand a vivid imagination.",
"The sun line on your palm sug-\ngests a radiant and successful\nphase in your life. Bask in the\nwarmth of your accomplishments.",
"The angle of your thumb shows a\nstrong sense of purpose.\nYou are resolute in your deci-\nsions, making it easier to\nachieve your goals.",
"The swirls and loops in your\nfingerprints are unique,\nmuch like your individuality.\nEmbrace your uniqueness, for\nit is your greatest strength.",
"The life line is long and un-\nbroken, foretelling a healthy\nand long life.\nTake care of your well-being\nto make the most of it.",

"A cross on your palm reflects a\ntime of spiritual awakening and\nself-discovery. Embrace the\njourney of inner transformation.",
"The presence of a square on your\npalm symbolizes stability and\ngrounding in your life.\nTrust in your ability to create\na strong foundation.",
"A chain-like pattern in your\npalm reveals a strong connection\nto others in your life.\nYour social bonds are vital to\nyour well-being.",
"A trident at the end of your\nfate line signifies success and\nrecognition in your chosen path.\nYour hard work will be rewarded.",
"The mount of Luna is well-\ndeveloped, indicating a deep\nconnection to your intuition\nand dreams.\nListen to your inner guidance.",
"A circle on your palm represents\nprotection and guidance from\nhigher forces. You are safe and\nguided on your life's journey.",
"The mound of Mercury is pronoun-\nced in your palm, reflecting\nstrong communication skills.\nUse this gift to express your\nthoughts effectively.",
"The mount of Jupiter is promi-\nnent, signifying leadership\nqualities. Take charge of your\nlife and guide it to success.",
"Your palm exudes an aura of\nresilience and determination.\nNo matter the challenge, you \npossess strength to overcome it.",
"The lines of your palm suggest\na strong connection with family\nand loved ones. Cherish these\nbonds, for they are a source of\nstrength.",

"Your thumb is well-proportioned,\nshowcasing your strong willpower\nand determination. You have the\npower to shape your destiny.",
"The fate line reveals a path\nfilled with twists and turns,\nbut it also shows great poten-\ntial for success and achievement.",
"A star on your mount of Saturn\nsignifies a time of discipline\nand wisdom.\nYour responsibilities will lead\nto great achievements.",
"Your intuition is heightened,\nwith a clear fate line guiding\nyou towards your innate talents.\nTrust your instincts in crucial\ndecisions.",
"A circle on your palm represents\ncycles of life and rebirth.\nYou are in a phase of transfor-\nmation, ready to emerge renewed.",
"Your head line suggests a sharp\nintellect and a thirst for know-\nledge. You possess a keen\nability to analyze and make sound\ndecisions.",
"Your heart line is deeply etched,\nsymbolizing strong emotional\nconnections. Nurture your rela-\ntionships, for they hold the key\nto happiness.",
"A star on your sun line suggests\na period of recognition and\nsuccess. Stay true to your goals,\nand you'll shine brightly.",
"I sense a great deal of determi-\nnation in your palm. With focus\nand persistence, you can over-\ncome any obstacle in your path.",
"In your palm, I see the poten-\ntial for a life filled with\nadventure and exploration.\nThe world is your oyster, and\nyou're meant to discover its\ntreasures.",
};


void setup() {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);   
  Serial1.begin(19200);  // Use the appropriate baud rate for your printer
  printer.begin();
}

void loop() {
  int fsrValue1 = analogRead(fsr1AnalogPin);     // the analog reading from the FSR1
  int fsrValue2 = analogRead(fsr2AnalogPin);     // the analog reading from the FSR2
  int fsrValue3 = analogRead(fsr3AnalogPin);     // the analog reading from the FSR3

  if (fsrValue1 > 150) fsr1 = true;
  else fsr1 = false;
  if (fsrValue2 > 150) fsr2 = true;
  else fsr2 = false;
  if (fsrValue3 > 150) fsr3 = true;
  else fsr3 = false;

  Serial.print("FSR1: ");
  Serial.println(fsrValue1);
  Serial.print("FSR2: ");
  Serial.println(fsrValue2);
  Serial.print("FSR3: ");
  Serial.println(fsrValue3);
  
  if (fsr1 && fsr2 && fsr3) {
    Serial.println("All pressed!");
    //Serial1.println("All pressed!");
    int i = random (0,69);
    printer.println(myStrings[i]);
    printer.println();
    printer.println();
    printer.println();
    printer.println();
    
    Serial.println (myStrings[i]);
    //  int n = split (20, myStrings[i], lines, MAX_LINES);
    //  Serial.println (n);

    // for (int i = 0; i < n; i++)
    //     Serial.println (lines [i]);

    printer.sleep();      // Tell printer to sleep
    delay(3000L);         // Sleep for 3 seconds
    printer.wake();       // MUST wake() before printing again, even if reset
    printer.setDefault(); // Restore printer to defaults
  }
  delay(1000);
}
