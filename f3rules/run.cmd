@echo off
rem Run f3rules over the scratch checkout into the evidence folder. Extra arguments are passed on (e.g. --jobs 24).
"%~dp0out\f3rules.exe" E:\f3-campaign\f3-scratch E:\f3-campaign\evidence\rules %*
