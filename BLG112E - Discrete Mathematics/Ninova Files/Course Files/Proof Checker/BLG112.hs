import Stdm

thDM1 = Theorem [Or (Not P) (Not Q)] (Not (And P Q))
thDM2 = Theorem [Not (Or (Not P) (Not Q))] (And P Q)

thDS = Theorem [Or P Q, Not P] Q
prDS =
  OrE
    (Assume (Or P Q),
     CTR (ImpE (Assume P, Assume (Imp P FALSE)) FALSE) Q,
     ID (Assume Q) Q)
    Q

thHS = Theorem [Imp P Q, Imp Q R] (Imp P R)
prHS =
  ImpI
    (ImpE
      (ImpE (Assume P, Assume (Imp P Q)) Q,
       Assume (Imp Q R))
      R)
  (Imp P R)

thMT = Theorem [Imp P Q, Not Q] (Not P)
prMT =
  Use thHS [Assume (Imp P Q), Assume (Imp Q FALSE)] (Imp P FALSE)

thContrapositive = Theorem [Imp P Q] (Imp (Not Q) (Not P))
prContrapositive =
  ImpI
    (Use thMT [Assume (Imp P Q), Assume (Not Q)] (Not P))
    (Imp (Not Q) (Not P))

thCD = Theorem [Imp P R, Imp Q S, Or P Q] (Or R S)
prCD =
  OrE
    (Assume (Or P Q),
     OrIL (ImpE (Assume P, Assume (Imp P R)) R) (Or R S),
     OrIR (ImpE (Assume Q, Assume (Imp Q S)) S) (Or R S))
    (Or R S)

thSpock = Theorem [P, Imp P Q, Imp Q R, Imp R S] S
prSpock =
  ImpE
    (Assume P,
     Use thHS
       [Use thHS [Assume (Imp P Q), Assume (Imp Q R)] (Imp P R),
        Assume (Imp R S)]
       (Imp P S))
    S

th1 = Theorem [Imp P R, Imp R S, Or X (Not S), Or U (Not X), Not U] (Not P)
pr1 =
  Use thMT
    [Assume (Imp P R),
     Use thMT
       [Assume (Imp R S),
        Use thDS
          [Assume (Or X (Not S)),
           Use thDS [Assume (Or U (Not X)), Assume (Imp U FALSE)] (Not X)]
          (Not S)]
        (Not R)]
    (Not P)

th2 = Theorem [Imp (Or (Not P) (Not Q)) (And R S), Imp R X, Not X] P
pr2 =
  AndEL
    (Use thDM2
       [Use thMT
          [Assume (Imp (Or (Not P) (Not Q)) (And R S)),
           Use thDM1
             [OrIL
               (Use thMT [Assume (Imp R X), Assume (Not X)] (Not R))
               (Or (Not R) (Not S))]
             (Not (And R S))]
          (Not (Or (Not P) (Not Q)))]
       (And P Q))
     P
