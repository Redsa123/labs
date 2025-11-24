package PrimeNumbers is
    type Sieve is array (Positive range <>) of Boolean ;
    type Sieve_Ptr is access Sieve;

    procedure Compute_Sieve (s: Sieve_Ptr);

    function Count_Primes (s: Sieve_Ptr) return Natural;

end PrimeNumbers;