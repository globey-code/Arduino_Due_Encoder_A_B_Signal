# Detect the Arduino Due Upload Port and Update platformio.ini

Write-Host "🔍 Searching for Arduino Due..."

# Get all serial ports
$serialPorts = Get-WMIObject Win32_SerialPort | Select-Object DeviceID, Name

# Filter for Arduino Due (Programming Port)
$arduinoDue = $serialPorts | Where-Object { $_.Name -match "Arduino Due" }

if ($arduinoDue) {
    # Extract COM port
    $uploadPort = $arduinoDue.DeviceID
    Write-Host "✅ Arduino Due detected on $uploadPort"

    # Read platformio.ini
    $iniPath = "platformio.ini"
    if (Test-Path $iniPath) {
        $iniContent = Get-Content $iniPath

        # Replace any existing upload_port line or add a new one
        $newIniContent = $iniContent -replace "upload_port\s*=\s*.*", "upload_port = $uploadPort"

        # If no existing upload_port line was found, add it
        if (-not ($newIniContent -match "upload_port = $uploadPort")) {
            $newIniContent += "`nupload_port = $uploadPort"
        }

        # Save the updated ini file
        $newIniContent | Set-Content $iniPath
        Write-Host "✅ Updated platformio.ini with upload_port = $uploadPort"
    } else {
        Write-Host "⚠️ platformio.ini not found!"
    }
} else {
    Write-Host "❌ No Arduino Due detected. Please connect the device and try again." -ForegroundColor Red
}
