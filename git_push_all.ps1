# PowerShell Script to Push All Changes to GitHub (Dynamic Project Detection)

# Get the current directory (assumes the script is inside the project folder)
$projectPath = Get-Location

Write-Host "🔄 Detected project directory: $projectPath"

# Check if it's a valid Git repository
if (!(Test-Path "$projectPath\.git")) {
    Write-Host "❌ This directory is not a Git repository. Please initialize it first using 'git init'." -ForegroundColor Red
    exit
}

# Check Git status
Write-Host "🔍 Checking for changes..."
git status

# Stage all changes (new, modified, and deleted files)
Write-Host "📌 Staging all changes..."
git add .

# Ask the user for a commit message
$commitMessage = Read-Host "✍️  Enter your commit message"

# Ensure the commit message is not empty
if ([string]::IsNullOrWhiteSpace($commitMessage)) {
    Write-Host "❌ Commit message cannot be empty. Please run the script again with a valid message." -ForegroundColor Red
    exit
}

# Commit changes with the user's message
git commit -m $commitMessage

# Push changes to GitHub
Write-Host "📤 Pushing changes to GitHub..."
git push origin main

# Verify if the push was successful
if ($?) {
    Write-Host "✅ Push completed successfully!" -ForegroundColor Green
} else {
    Write-Host "❌ Push failed! Try running 'git pull origin main --rebase' first." -ForegroundColor Red
}
